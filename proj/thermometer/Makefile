LIBDIR=../../mclib/

BINARY=thermometer
SOURCES=thermometer.c one_wire.c ds18b20.c

MCU=atmega8
MCU_ARCH=avr

# 8Mhz
CPU_FREQ=8000

# 8Mhz internal RC, the 1Mhz is not fast enough for sw one wire
LFUSE=0xE4
# default
HFUSE=0xD9

include $(LIBDIR)skel.mk
