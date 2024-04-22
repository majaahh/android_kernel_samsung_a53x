# Exynos FMP makefile
ccflags-y += -I$(srctree)/drivers/scsi/ufs/s5e8825

fmp-core-y += fmp.o

.PHONY: fips_clean
fips_clean:
	@echo " Clean FIPS module artefacts .... "
	@rm -f $(objtree)/drivers/crypto/fmp/fipsed_*.c
	@rm -f $(objtree)/drivers/crypto/fmp/fips140_ic_support.c
	@rm -f $(objtree)/drivers/crypto/fmp/*.o
	@sync
	@echo " Clean FIPS module artefacts completed "
