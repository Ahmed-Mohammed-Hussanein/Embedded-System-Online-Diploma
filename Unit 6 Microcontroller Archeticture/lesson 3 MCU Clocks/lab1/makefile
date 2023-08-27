# Ahmed Mohammed Hussanein Ali

CC =arm-none-eabi-
CFLAGS =-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS =-I .
LIBS =
CSRC = $(wildcard *.c)
COBJ = $(CSRC:.c=.o)
ASRC = $(wildcard *.s)
AOBJ = $(ASRC:.s=.o)
PROJ =lesson3_lab1

all: $(PROJ).bin
	@echo "========= Successful Build ========="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJ).elf: $(COBJ) $(AOBJ)
	$(CC)ld.exe -T LinkerScript.ld $(LIBS) -Map=mapfile.map $(COBJ) $(AOBJ) -o $@
	cp $(PROJ).elf $(PROJ).axf

$(PROJ).bin: $(PROJ).elf
	$(CC)objcopy.exe -O binary $< $@

clean: 
	rm *.elf *.bin

clean_all: 
	rm *.o *.elf *.bin