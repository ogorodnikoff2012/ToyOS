SOURCES=boot.o main.o common.o monitor.o descriptor_tables.o gdt.o \
	interrupt.o isr.o 

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-melf_i386 -Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) link

clean: 
	-rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<

