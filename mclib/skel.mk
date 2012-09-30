#
# Include MCU specific Makefile
#
include $(LIBDIR)config_$(MCU_ARCH).mk

help:
	@ echo "Targets:"
	@ echo "make help             -- prints this help"
	@ echo "make                  -- compile code"
	@ echo "make load             -- compile and load code to $(MCU)"
	@ echo "make show_fuses       -- show fuses (for avr only)"
	@ echo "make load_fuses       -- loads fuses (for avr only)"
	@ echo "make disasm           -- compile and show dissasembled result"
	@ echo "make prog_shell       -- enter avrdude shell"
	@ echo "make clean            -- clean all temporary files"
	@ echo "make check_programmer -- tries to check programmer functionality"
