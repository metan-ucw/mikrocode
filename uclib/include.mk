# for MCU and MCU_ARCH from project
PROJECT_PATH=$(shell echo $$PROJECT_PATH)
include $(PROJECT_PATH)/config.mk
# for MCU_BUILD_DIR
LIBDIR=$(TOPDIR)
include $(TOPDIR)/config.mk
# for CC, OBJCOPY, CFLAGS
include $(TOPDIR)/compile.mk

ifdef SOURCES
	OBJECTS=$(addprefix $(MCU_BUILD_DIR), $(SOURCES:.c=.o))
endif

ifdef INCLUDE
	CFLAGS+=$(addprefix -I$(TOPDIR)/include/, $(INCLUDE))
endif

all: $(OBJECTS) $(SUBDIRS)

.PHONY: clean $(SUBDIRS)

$(SUBDIRS):
	@ echo "MAKE $@"
	@ $(MAKE) --no-print-directory -C $@ $(MAKECMDGOALS)

clean: $(SUBDIRS)

#
# Library build rule
#
$(MCU_BUILD_DIR)%.o: %.c
	@ echo "CC   ($(MCU)) $<"
	@ $(CC) $(CFLAGS) -c $< -o $@

ifdef CLEAN
clean:
	rm -rf $(CLEAN)
endif
