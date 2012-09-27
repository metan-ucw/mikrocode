#
# Library generic build rule
#
LIBBUILDDIR=.mclib/
CLEAN+=$(LIBBUILDDIR)

library:
ifndef VERBOSE
	@ if ! [ -e $(LIBBUILDDIR) ]; then mkdir $(LIBBUILDDIR)/; fi
	@ $(MAKE) MCU="$(MCU)" MCU_ARCH="$(MCU_ARCH)" LIBDIR="$(LIBDIR)" LIBBUILDDIR="$(PWD)/$(LIBBUILDDIR)" -C $(LIBDIR) --no-print-directory
else
	if ! [ -e $(LIBBUILDDIR) ]; then mkdir $(LIBBUILDDIR)/; fi
	$(MAKE) MCU="$(MCU)" MCU_ARCH="$(MCU_ARCH)" LIBDIR="$(LIBDIR)" LIBBUILDDIR="$(PWD)/$(LIBBUILDDIR)" -C $(LIBDIR)
endif
