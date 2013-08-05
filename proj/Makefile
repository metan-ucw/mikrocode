SUBDIRS=blink generator ds1307_test hd44780u_test thermometer

.PHONY: $(SUBDIRS)

all:   $(SUBDIRS)
clean: $(SUBDIRS)

$(SUBDIRS):
	@ echo "PROJ $@"
	@ cd $@ && $(MAKE) --no-print-directory $(MAKECMDGOALS)
