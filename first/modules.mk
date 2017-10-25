mod_first.la: mod_first.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_first.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_first.la
