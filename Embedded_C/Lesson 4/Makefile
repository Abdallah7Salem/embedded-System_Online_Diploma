#@copyright : Abdallah Salem
CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -gdwarf-2 -g
INCS = -I .
LIBS = 
SRC = $(wildcard *.c) # Da m3nah 5od m3ak kol 7agah fiha .c
OBJ = $(SRC:.c=.o)    # Da m3nah 5od ay 7agah .c 7otaha .o 
As = $(wildcard *.s)  # Da m3nah 5od m3ak ay 7agah .s
AsOBJ = $(As:.s=.o)   # Da m3nah 5od ay 7agah .s 7otaha .o
project_name = unit3_lab4_cortexM4

# This line is to make not cause error which is interrupt during make clean
SHELL=C:/Windows/System32/cmd.exe


all: $(project_name).bin
	@echo "Build is done"
	
%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS)  $< -o $@


$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin