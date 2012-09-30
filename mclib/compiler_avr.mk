#
# Compiler/Linker settings for AVR MCUs
#
CC=avr-gcc
OBJCOPY=avr-objcopy
OBJDUMP=avr-objdump
CFLAGS+=-mcall-prologues -mmcu=$(MCU) -Wall -W -std=c99 -Os
# enable dead-code elimination
LDFLAGS+=-Wl,--gc-sections

#
# If CPU frequency is set as a static number add it to CFLAGS
#
ifdef CPU_FREQ
CFLAGS+=-DCPU_FREQ=$(CPU_FREQ)
endif

#
# Add paths to library headers 
#
# If TOPDIR is defined we are included from a library Makefile and we use
# relative path to the headers. If not set, we are included form a project
# Makefile and we rely on LIBDIR path.
#
ifdef TOPDIR
	LIBPREFIX=$(TOPDIR)
else
	LIBPREFIX=$(LIBDIR)
endif

INCLUDE+=-I$(LIBPREFIX)/include/generic
INCLUDE+=-I$(LIBPREFIX)/include/$(MCU_ARCH)/generic

# TODO: MCU specific include here
ifeq ($(MCU),atmega8)
INCLUDE+=-I$(LIBPREFIX)/include/$(MCU_ARCH)/$(MCU)
endif

#
# Compiler rule
#
$(OUTDIR)%.o: %.c
ifndef VERBOSE
	@ echo "CC   ($(MCU)) $<"
	@ $(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@
else
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@
endif
