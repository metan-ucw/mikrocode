#
# Compiles object files in current directory into project build directory. 
#
OUTDIR=$(LIBBUILDDIR)
include $(TOPDIR)compiler_$(MCU_ARCH).mk

SOURCES=$(wildcard *.c)
OBJECTS=$(addprefix $(LIBBUILDDIR), $(SOURCES:.c=.o))

all: $(OBJECTS)
