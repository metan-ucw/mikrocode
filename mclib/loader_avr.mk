#
# paraell port programmer
#

#DPROG=dapa
#DLPT=/dev/parport0

#load: $(BINARY).hex
#	uisp -dlpt=$(DLPT) -dprog=$(DPROG) --erase
#	uisp -dlpt=$(DLPT) -dprog=$(DPROG) --upload if=$(BINARY).hex
#	uisp -dlpt=$(DLPT) -dprog=$(DPROG) --verify if=$(BINARY).hex

#check_programmer:
#	uisp -dlpt=$(DLPT) -dprog=$(DPROG)

#
# AVR isp programmer
#
PROGRAMMER=stk500v2
PROGRAMMER_PARAMS=-P /dev/ttyUSB0 -B 10

#
# AVR dragon isp
#
#PROGRAMMER=dragon_isp
#PROGRAMMER_PARAMS=-P usb -B 10

load: $(BINARY).hex
	avrdude -p $(MCU) -c $(PROGRAMMER) $(PROGRAMMER_PARAMS) -U flash:w:$(BINARY).hex

show_fuses:
	avrdude -p $(MCU) -c $(PROGRAMMER) $(PROGRAMMER_PARAMS) -U hfuse:r:-:h -U lfuse:r:-:h

load_fuses:
	avrdude -p $(MCU) -c $(PROGRAMMER) $(PROGRAMMER_PARAMS) -U hfuse:w:$(HFUSE):m -U lfuse:w:$(LFUSE):m

prog_shell:
	avrdude -p $(MCU) -c $(PROGRAMMER) $(PROGRAMMER_PARAMS) -t

check_programmer:
	avrdude -p $(MCU) -c $(PROGRAMMER) $(PROGRAMMER_PARAMS)

