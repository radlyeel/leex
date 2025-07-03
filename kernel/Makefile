# TODO grok this
CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

# Get path from $ which aarch64-none-elf-gcc
GCCPATH = /usr/local/bin

all: clean kernel8.img

boot.o: boot.S
	$(GCCPATH)/aarch64-elf-gcc $(GCCFLAGS) -c boot.S -o boot.o

%.o: %.c
	$(GCCPATH)/aarch64-elf-gcc $(GCCFLAGS) -c $< -o $@

kernel8.img: boot.o $(OFILES)
	$(GCCPATH)/aarch64-elf-ld -nostdlib boot.o $(OFILES) -T link.ld -o kernel8.elf
	$(GCCPATH)/aarch64-elf-objcopy -O binary kernel8.elf kernel8.img

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true
