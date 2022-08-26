# @CopyRight: Ahmed Mohammed Hussanein Ali
# Environment Variable
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g -mthumb
INCS=-I .
LIBS= 
CSRC = $(wildcard *.c)
COBJ = $(CSRC:.c=.o)
ASRC = $(wildcard *.s)
AOBJ = $(ASRC:.s=.o)
PRONAME =lab3_CortexM4


all: $(PRONAME).bin
	@echo "========= Successful Build ========="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(PRONAME).elf: $(AOBJ) $(COBJ)
	$(CC)ld.exe -T LinkerScript.ld $(LIBS) -Map=output.map $(AOBJ) $(COBJ) -o $@
	cp $(PRONAME).elf $(PRONAME).axf
	
$(PRONAME).bin: $(PRONAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin