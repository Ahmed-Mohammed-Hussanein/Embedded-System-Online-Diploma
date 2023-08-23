CC=arm-none-eabi-
CFLAGS=-g -gdwarf-2 -mcpu=cortex-m3 -mthumb
INC=-I .
LIBS=

CSRC=$(wildcard *.c)
COBJ=$(CSRC:.c=.o)
SSRC=$(wildcard *.s)
SOBJ=$(SSRC:.s=.o)


PROJ=PressureDetectionProject


all: $(PROJ).bin
	@echo " ======================= Successful Build ======================= "

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INC) $< -o $@

$(PROJ).elf: $(COBJ) $(SOBJ)
	$(CC)ld.exe -T linkerscript.ld $(LIBS) $(COBJ) $(SOBJ) -o $@ -Map=map_file.map

$(PROJ).bin: $(PROJ).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.o

clean_all:
	rm *.o *.elf *.bin