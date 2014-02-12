#
# This file is part of Mikrocode.
#

SUBDIRS=$(filter-out Makefile,$(wildcard *))

.PHONY: $(SUBDIRS)

all:   $(SUBDIRS)
clean: $(SUBDIRS)

$(SUBDIRS):
	@ echo "PROJ $@"
	@ cd $@ && $(MAKE) --no-print-directory $(MAKECMDGOALS)
