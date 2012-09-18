SUBDIRS=blink

.PHONY: $(SUBDIRS)

all:   $(SUBDIRS)
clean: $(SUBDIRS)

$(SUBDIRS):
	@ echo "PROJ $@"
	@ cd $@ && $(MAKE) --no-print-directory $(MAKECMDGOALS)
