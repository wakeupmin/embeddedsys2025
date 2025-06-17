CC = arm-linux-gnueabi-gcc
AR = arm-linux-gnueabi-gcc

all: libMyperi.a ledtest buttontest buzzertest

ledtest.elf: ledtest.c libMyperi.a
		$(CC) ledtest.c -lMyPeri -L. -o ledtest.elf
	
buttontest.elf: buttontest.c libMyperi.a
		$(CC) buttontest.c -lMyPeri -L. -lpthread -o buttontest.elf

buzzertest.elf: buzzertest.c libMyperi.a
		$(CC) buzzertest.c -lMyPeri -L. -lpthread -o buzzertest.elf

libMyperi.a: button.o led.o buzzer.o
	$(AR) rc libMyperi.a led.o button.o buzzer.o

buzzer.o: buzzer.h buzzer.c
		$(CC) -c buzzer.c -o buzzer.o

button.o: button.h button.c
		$(CC) -c button.c -o button.o

led.o: led.h led.c
		$(CC) -c led.c -o led.o

clean:
	rm *.o *.a *.elf
