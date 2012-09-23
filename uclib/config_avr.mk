OBJECTS=$(SOURCES:.c=.o)
DEPFILES=$(SOURCES:.c=.dep)

#
# Main target for AVR MCU is hex file
#
all: $(BINARY).hex $(DEPFILES)

#
# Include compiler settings and rule
#
include $(LIBDIR)compiler_avr.mk

#
# Automatic dependecies
#
-include $(DEPFILES)

$(DEPFILES): %.dep: %.c
ifdef VERBOSE
	$(CC) -MM $(CFLAGS) $(INCLUDE) $< -o $@
else
	@ echo "DEP  $@"
	@ $(CC) -MM $(CFLAGS) $(INCLUDE) $< -o $@
endif

#
# Include library build rules
#
# This file defines target library which build library sources into project
# directory. Also provides variable LIBBUILDDIR that points to this directory.
#
include $(LIBDIR)lib.mk

$(LIBBUILDDIR)/*.o: library

#
# Linker rule
#
$(BINARY).ld: $(OBJECTS) $(LIBBUILDDIR)/*.o
	@ echo "LD   $(BINARY).ld"
	@ $(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(LIBBUILDDIR)/*.o -o $(BINARY).ld

#
# Hex converter rule
#
$(BINARY).hex: $(BINARY).ld
	@ echo "CONV $(BINARY).hex"
	@ $(OBJCOPY) -O ihex $(BINARY).ld $(BINARY).hex

#
# Disassembler rule
#
disasm: $(BINARY).ld
	@ $(OBJDUMP) -d $(BINARY).ld | less

#
# Programmer related functions
#
include $(LIBDIR)loader_avr.mk
	
CLEAN+=$(LIBBUILDDIR) $(BINARY).ld $(BINARY).hex $(OBJECTS) $(DEPFILES)

clean:
ifndef VERBOSE
	@echo "RM   $(BINARY)"
	@rm -rf $(CLEAN)
else
	rm -rf $(CLEAN)
endif
