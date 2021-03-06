#
# This file is part of Mikrocode.
#
# Library generic build rule
#
LIBBUILDDIR=lib/
CLEAN+=$(LIBBUILDDIR)

library:
ifndef VERBOSE
	@ if ! [ -e $(LIBBUILDDIR) ]; then mkdir $(LIBBUILDDIR)/; fi
	@ $(MAKE) MCU="$(MCU)" MCU_ARCH="$(MCU_ARCH)" CPU_FREQ="$(CPU_FREQ)" LIBDIR="$(LIBDIR)" LIBBUILDDIR="$(PWD)/$(LIBBUILDDIR)" -C $(LIBDIR) --no-print-directory
else
	if ! [ -e $(LIBBUILDDIR) ]; then mkdir $(LIBBUILDDIR)/; fi
	$(MAKE) MCU="$(MCU)" MCU_ARCH="$(MCU_ARCH)" CPU_FREQ="$(CPU_FREQ)" LIBDIR="$(LIBDIR)" LIBBUILDDIR="$(PWD)/$(LIBBUILDDIR)" -C $(LIBDIR)
endif
