# TODO grok this
CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)

GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
GCCPATH =  $(HOME)/aarch64/arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf
DEST = $(SDCARD)/bootfs

CC = $(GCCPATH)/bin/aarch64-none-elf-gcc
OBJCOPY = $(GCCPATH)/bin/aarch64-none-elf-objcopy
LD = $(GCCPATH)/bin/aarch64-none-elf-ld


all: clean kernel8.img

boot.o: boot.S
	$(CC) $(GCCFLAGS) -c boot.S -o boot.o

%.o: %.c
	$(CC) $(GCCFLAGS) -c $< -o $@

kernel8.img: boot.o $(OFILES)
	$(LD) -nostdlib boot.o $(OFILES) -T link.ld -o kernel8.elf
	$(OBJCOPY) -O binary kernel8.elf kernel8.img

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true

install: kernel8.img
	sudo rm -f $(DEST)/kernel*
	sudo cp kernel8.img $(DEST)
	sudo umount $(DEST)
