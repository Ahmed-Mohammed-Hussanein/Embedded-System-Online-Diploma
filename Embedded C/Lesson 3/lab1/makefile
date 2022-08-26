# Ahmed Mohammed Hussanein Ali 

CC =arm-none-eabi-
CFLAGS =-mcpu=arm926ej-s -g
INCS =-I .
LIBS =
CSRC = $(wildcard *.c)
COBJ = $(CSRC:.c=.o)
ASRC = $(wildcard *.s)
AOBJ = $(ASRC:.s=.o)
PROJ =learn-in-depth-lab1

all: $(PROJ).bin
	@echo "========= Successful Build ========="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJ).elf: $(COBJ) $(AOBJ)
	$(CC)ld.exe -T LinkerScript.ld $(LIBS) -Map=mapfile.map $(COBJ) $(AOBJ) -o $@

$(PROJ).bin: $(PROJ).elf
	$(CC)objcopy.exe -O binary $< $@

clean: 
	rm *.elf *.bin

clean_all: 
	rm *.o *.elf *.bin