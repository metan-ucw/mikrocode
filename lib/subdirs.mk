#
# This file is part of Mikrocode.
#

all: $(SUBDIRS)

.PHONY: $(SUBDIRS)

$(SUBDIRS):
ifndef VERBOSE
	@ echo "MK   $(CURSUBDIR)/$@"
	@ CURSUBDIR="$(CURSUBDIR)/$@" $(MAKE) --no-print-directory -C $@
else
	$(MAKE) -C $@
endif
