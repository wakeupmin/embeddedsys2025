CC = arm-linux-gnueabi-gcc
AR = arm-linux-gnueabi-ar

all: libMyPeri.a ledtest.elf buttontest.elf buzzertest.elf fndtest.elf

ledtest.elf: ledtest.c libMyPeri.a
		$(CC) ledtest.c -lMyPeri -L. -o ledtest.elf
	
buttontest.elf: buttontest.c libMyPeri.a
		$(CC) buttontest.c -lMyPeri -L. -lpthread -o buttontest.elf

buzzertest.elf: buzzertest.c libMyPeri.a
		$(CC) buzzertest.c -lMyPeri -L. -lpthread -o buzzertest.elf

fndtest.elf: fndtest.c libMyPeri.a
		$(CC) fndtest.c -lMyPeri -L. -lpthread -o fndtest.elf

libMyPeri.a: button.o led.o buzzer.o fnd.o
	$(AR) rc libMyPeri.a led.o button.o buzzer.o fnd.o

fnd.o: fnd.h fnd.c
	$(CC) -c fnd.c -o fnd.o

buzzer.o: buzzer.h buzzer.c
		$(CC) -c buzzer.c -o buzzer.o

button.o: button.h button.c
		$(CC) -c button.c -o button.o

led.o: led.h led.c
		$(CC) -c led.c -o led.o


clean:
	rm *.o *.a *.elf
