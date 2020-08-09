all: libLcd.a toy.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h 
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib 
#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

font-6x8.o: font-6x8.c

libLcd.a: font-5x7.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

lcdutils.o: lcdutils.c lcdutils.h lcdtypes.h
lcddraw.o: lcddraw.c lcddraw.h lcdutils.h font-6x8.o

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libLcd.a *.o *.elf

erase:
	rm -f *~ *#

toy.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o toyMain.o ../lib/libTimer.a buzzer.o stateMachines.o wdInterruptHandler.o libLcd.a toggleLed.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

load: toy.elf
	msp430loader.sh $^
