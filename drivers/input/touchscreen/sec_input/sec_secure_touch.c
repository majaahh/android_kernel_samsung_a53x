/*
 * sec_secure_touch.c - samsung secure touch driver
 *
 * Copyright (C) 2018 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

struct sec_secure_touch *g_ss_touch;

#include "sec_secure_touch.h"
#include <linux/notifier.h>
#include "sec_input.h"

int sec_secure_touch_set_device(struct sec_secure_touch *data, int dev_num);
void sec_secure_touch_sysfs_notify(struct sec_secure_touch *data);

int sec_secure_touch_set_device(struct sec_secure_touch *data, int dev_num)
{
	int number = dev_num - 1;
	int ret;

	if (data->touch_driver[number].registered == 0)
		return -ENODEV;

	if (data->device_number > 1)
		return -EBUSY;

	mutex_lock(&data->lock);
	ret = sysfs_create_link(&data->device->kobj, data->touch_driver[number].kobj, "secure");
	if (ret < 0) {
		mutex_unlock(&data->lock);
		return -EINVAL;
	}

	pr_info("%s: %s: create link ret:%d, %s\n", SECLOG, __func__, ret, data->touch_driver[number].kobj->name);

	data->touch_driver[number].enabled = 1;

	mutex_unlock(&data->lock);

	return ret;
}

struct sec_touch_driver *sec_secure_touch_register(void *drv_data, int dev_num, struct kobject *kobj)
{
	struct sec_secure_touch *data = g_ss_touch;
	int number = dev_num - 1;

	if (!data) {
		pr_info("%s %s: null\n", SECLOG, __func__);
		return NULL;
	}

	pr_info("%s %s\n", SECLOG, __func__);

	if (dev_num < 1) {
		dev_err(&data->pdev->dev, "%s: invalid parameter:%d\n", __func__, dev_num);
		return NULL;
	}

	if (data->touch_driver[number].registered) {
		dev_info(&data->pdev->dev, "%s: already registered device number\n", __func__);
		return NULL;
	}

	pr_info("%s %s: name is %s\n", SECLOG, __func__, kobj->name);
	data->touch_driver[number].drv_number = dev_num;
	data->touch_driver[number].drv_data = drv_data;
	data->touch_driver[number].kobj = kobj;
	data->touch_driver[number].registered = 1;

	data->device_number++;

	sec_secure_touch_set_device(data, dev_num);

	return &data->touch_driver[number];
}
EXPORT_SYMBOL(sec_secure_touch_register);


void sec_secure_touch_unregister(int dev_num)
{
	struct sec_secure_touch *data = g_ss_touch;
	int number = dev_num - 1;

	pr_info("%s: %s\n", SECLOG, __func__);

	data->touch_driver[number].drv_number = 0;
	data->touch_driver[number].drv_data = NULL;
	data->touch_driver[number].kobj = NULL;
	data->touch_driver[number].registered = 0;

	data->device_number--;

}

void sec_secure_touch_sysfs_notify(struct sec_secure_touch *data)
{
	if (!data)
		sysfs_notify(&g_ss_touch->device->kobj, NULL, "secure_touch");
	else
		sysfs_notify(&data->device->kobj, NULL, "secure_touch");

	dev_info(&g_ss_touch->pdev->dev, "%s\n", __func__);
}

static ssize_t secure_dev_count_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct sec_secure_touch *data = dev_get_drvdata(dev);

	if (!data)
		return -ENOMEM;

	return snprintf(buf, PAGE_SIZE, "%d", data->device_number);
}

static DEVICE_ATTR(dev_count, 0444, secure_dev_count_show, NULL);

static struct attribute *sec_secure_touch_attrs[] = {
	&dev_attr_dev_count.attr,
	NULL,
};

static struct attribute_group sec_secure_touch_attr_group = {
	.attrs = sec_secure_touch_attrs,
};

static int sec_secure_touch_probe(struct platform_device *pdev)
{
	struct sec_secure_touch *data;
	int ret;

	data = kzalloc(sizeof(struct sec_secure_touch), GFP_KERNEL);
	if (!data) {
		pr_info("%s %s: failed probe: mem\n", SECLOG, __func__);
		return -ENOMEM;
	}
	data->pdev = pdev;

	data->device = sec_device_create(data, SECURE_TOUCH_DEV_NAME);
	if (IS_ERR(data->device)) {
		pr_info("%s %s: failed probe: create\n", SECLOG, __func__);
		kfree(data);
		return -ENODEV;
	}

	g_ss_touch = data;

	dev_set_drvdata(data->device, data);

	platform_set_drvdata(pdev, data);

	mutex_init(&data->lock);

	ret = sysfs_create_group(&data->device->kobj, &sec_secure_touch_attr_group);
	if (ret < 0) {
		pr_info("%s %s: failed probe: create sysfs\n", SECLOG, __func__);
		sec_device_destroy(data->device->devt);
		g_ss_touch = NULL;
		kfree(data);
		return -ENODEV;
	}

	sec_secure_touch_set_device(data, 1);
	pr_info("%s: %s\n", SECLOG, __func__);

	return 0;
}

static int sec_secure_touch_remove(struct platform_device *pdev)
{
	struct sec_secure_touch *data = platform_get_drvdata(pdev);
	int ii;

	pr_info("%s: %s\n", SECLOG, __func__);
	for (ii = 0; ii < data->device_number; ii++) {
		if (data->touch_driver[ii].enabled)
			sysfs_remove_link(&data->device->kobj, "secure");

		sysfs_remove_group(&data->device->kobj, &sec_secure_touch_attr_group);
	}

	mutex_destroy(&data->lock);
	sec_device_destroy(data->device->devt);

	g_ss_touch = NULL;
	kfree(data);
	return 0;
}

#if CONFIG_OF
static const struct of_device_id sec_secure_touch_dt_match[] = {
	{ .compatible = "samsung,ss_touch" },
	{}
};
#endif

struct platform_driver sec_secure_touch_driver = {
	.probe = sec_secure_touch_probe,
	.remove = sec_secure_touch_remove,
	.driver = {
		.name = "sec_secure_touch",
		.owner = THIS_MODULE,
#if CONFIG_OF
		.of_match_table = of_match_ptr(sec_secure_touch_dt_match),
#endif
	},
};

static int __init sec_secure_touch_init(void)
{
	pr_info("%s: %s\n", SECLOG, __func__);

	platform_driver_register(&sec_secure_touch_driver);
	return 0;
}

static void __exit sec_secure_touch_exit(void)
{
	pr_info("%s; %s\n", SECLOG, __func__);

};

module_init(sec_secure_touch_init);
module_exit(sec_secure_touch_exit);

MODULE_DESCRIPTION("Samsung Secure Touch Driver");
MODULE_LICENSE("GPL");

