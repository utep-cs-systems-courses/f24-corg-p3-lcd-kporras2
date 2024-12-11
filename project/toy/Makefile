COMMON_OBJECTS	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-gcc -mmcu=${CPU} -c

all: project.elf

project.elf: ${COMMON_OBJECTS} main.c stateMachines.o led.o wdInterruptHandler.o p2_interrupt_handler.o switches.o buzzer.o images.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: project.elf
	msp430loader.sh project.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

images.o: images.c images.h

stateMachines.o: stateMachines.c stateMachines.h

buzzer.o: buzzer.c buzzer.h

switches.o: switches.c switches.h

wdInterruptHandler.o: wdInterruptHandler.c

p2_interrupt_handler.o: p2_interrupt_handler.c
