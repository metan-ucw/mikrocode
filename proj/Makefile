SUBDIRS=blink generator ds1307_test

.PHONY: $(SUBDIRS)

all:   $(SUBDIRS)
clean: $(SUBDIRS)

$(SUBDIRS):
	@ echo "PROJ $@"
	@ cd $@ && $(MAKE) --no-print-directory $(MAKECMDGOALS)
