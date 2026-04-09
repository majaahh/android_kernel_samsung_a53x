/* SPDX-License-Identifier: GPL-2.0-only */
/*
* Samsung debugging features for Samsung's SoC's.
*
* Copyright (c) 2019 Samsung Electronics Co., Ltd.
*      http://www.samsung.com
*/

#ifndef SEC_DEBUG_H
#define SEC_DEBUG_H

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/types.h>
/*
 * Don't include additional headers. They can cause ABI violation problem
 * because this file is included many built-in drivers.
 */

struct task_struct;
struct irq_desc;
struct pt_regs;
struct freq_log;

/*
 * SEC DEBUG LAST KMSG
 */
#define secdbg_lkmg_store(a, b, c)		do {} while(0)

/*
 * SEC DEBUG MODE
 */
static inline int secdbg_mode_check_sj(void)
{
	return 0;
}
static inline int secdbg_mode_enter_upload(void)
{
	return 0;
}

/*
 * SEC DEBUG - DEBUG SNAPSHOT BASE HOOKING
 */
enum {
	DSS_KEVENT_TASK,
	DSS_KEVENT_WORK,
	DSS_KEVENT_IRQ,
	DSS_KEVENT_FREQ,
	DSS_KEVENT_IDLE,
	DSS_KEVENT_THRM,
	DSS_KEVENT_ACPM,
	DSS_KEVENT_MFRQ,
};

#define SD_ESSINFO_KEY_SIZE	(32)

struct ess_info_offset {
	char key[SD_ESSINFO_KEY_SIZE];
	unsigned long base;
	unsigned long last;
	unsigned int nr;
	unsigned int size;
	unsigned int per_core;
};

/*
 * SEC DEBUG AUTO COMMENT
 */
#define DEFINE_STATIC_PR_AUTO_NAME_ONCE(name, lvl)
#define pr_auto_name_once(name)
#define pr_auto_name(name, fmt, ...)	pr_emerg(fmt, ##__VA_ARGS__)
#define pr_auto_name_disable(name)
#define pr_auto_name_on(__pr_auto_cond, name, fmt, ...)		pr_emerg(fmt, ##__VA_ARGS__)
#define pr_auto_on(__pr_auto_cond, lvl, fmt, ...)		pr_emerg(fmt, ##__VA_ARGS__)

#define secdbg_exin_set_finish(a)	do { } while (0)
#define secdbg_exin_set_panic(a)	do { } while (0)
#define secdbg_exin_set_busmon(a)	do { } while (0)
#define secdbg_exin_set_sysmmu(a)	do { } while (0)
#define secdbg_exin_set_smpl(a)		do { } while (0)
#define secdbg_exin_set_decon(a)	do { } while (0)
#define secdbg_exin_set_batt(a, b, c, d)	do { } while (0)
#define secdbg_exin_set_mfc_error(a)	do { } while (0)
#define secdbg_exin_set_aud(a)		do { } while (0)
#define secdbg_exin_set_gpuinfo(a)		do { } while (0)
#define secdbg_exin_set_epd(a)		do { } while (0)
#define secdbg_exin_set_asv(a)		do { } while (0)
#define secdbg_exin_set_ids(a)		do { } while (0)
#define secdbg_exin_set_unfz(a)		do { } while (0)
#define secdbg_exin_get_unfz()		(NULL)
#define secdbg_exin_set_hardlockup_type(a, ...)	do { } while (0)
#define secdbg_exin_set_hardlockup_data(a)	do { } while (0)
#define secdbg_exin_set_hardlockup_freq(a, b)	do { } while (0)
#define secdbg_exin_set_hardlockup_ehld(a, b)	do { } while (0)
#define secdbg_exin_set_ufs(a)		do { } while (0)

#define secdbg_wdd_set_keepalive(a)	do { } while (0)
#define secdbg_wdd_set_start(a)		do { } while (0)
#define secdbg_base_built_wdd_set_emerg_addr(a)	do { } while (0)

/* unfrozen task */
static inline void secdbg_base_built_set_unfrozen_task(struct task_struct *task, uint64_t count) {}

/* CONFIG_SEC_DEBUG_BAD_STACK_INFO */
extern void secdbg_base_set_bs_info_phase(int phase);

#define secdbg_dtsk_built_set_data(a)	    do { } while (0)
#define secdbg_dtsk_built_clear_data()		do { } while (0)

#define secdbg_base_built_set_device_shutdown_timeinfo(a, b, c, d)	do { } while (0)
#define secdbg_base_built_clr_device_shutdown_timeinfo()	do { } while (0)
#define secdbg_base_built_set_shutdown_device(a, b)		do { } while (0)
#define secdbg_base_built_set_suspend_device(a, b)		do { } while (0)

#define secdbg_base_built_set_task_in_pm_suspend(a)		do { } while (0)
#define secdbg_base_built_set_task_in_sync_irq(a, b, c)		do { } while (0)

#define secdbg_softdog_show_info()		do { } while (0)

static inline void secdbg_base_built_check_handle_bad_stack(void) { }

#define SECDBG_DEFINE_MEMBER_TYPE(a, b, c)

extern struct atomic_notifier_head sec_power_off_notifier_list;

extern void secdbg_exin_set_main_ocp(void *main_ocp_cnt, void *main_oi_cnt, int buck_cnt);

#endif /* SEC_DEBUG_H */
