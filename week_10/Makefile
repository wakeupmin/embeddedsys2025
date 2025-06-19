CC = arm-linux-gnueabi-gcc
AR = arm-linux-gnueabi-ar

all: libMyPeri.a ledtest.elf buttontest.elf buzzertest.elf fndtest.elf textlcdtest.elf colorledtest.elf accelMagGyrotest.elf temperaturetest.elf

ledtest.elf: ledtest.c libMyPeri.a
		$(CC) ledtest.c -lMyPeri -L. -o ledtest.elf
	
buttontest.elf: buttontest.c libMyPeri.a
		$(CC) buttontest.c -lMyPeri -L. -lpthread -o buttontest.elf

buzzertest.elf: buzzertest.c libMyPeri.a
		$(CC) buzzertest.c -lMyPeri -L. -lpthread -o buzzertest.elf

fndtest.elf: fndtest.c libMyPeri.a
		$(CC) fndtest.c -lMyPeri -L. -lpthread -o fndtest.elf

textlcdtest.elf: textlcdtest.c libMyPeri.a
		$(CC) textlcdtest.c -lMyPeri -L. -lpthread -o textlcdtest.elf

colorledtest.elf: colorledtest.c libMyPeri.a
		$(CC) colorledtest.c -lMyPeri -L. -lpthread -o colorledtest.elf

temperaturetest.elf: temperaturetest.c libMyPeri.a
		$(CC) temperaturetest.c -lMyPeri -L. -lpthread -o temperaturetest.elf

accelMagGyrotest.elf: accelMagGyrotest.c libMyPeri.a
		$(CC) accelMagGyrotest.c -lMyPeri -L. -lpthread -o accelMagGyrotest.elf

libMyPeri.a: button.o led.o buzzer.o fnd.o textlcd.o colorled.o accelMagGyro.o temperature.o
	$(AR) rc libMyPeri.a led.o button.o buzzer.o fnd.o textlcd.o colorled.o accelMagGyro.o temperature.o

accelMagGyro.o: accelMagGyro.h accelMagGyro.c
	$(CC) -c accelMagGyro.c -o accelMagGyro.o

temperature.o: temperature.h temperature.c	
	$(CC) -c temperature.c -o temperature.o

colorled.o: colorled.h colorled.c
	$(CC) -c colorled.c -o colorled.o	

textlcd.o: textlcd.h textlcd.c
	$(CC) -c textlcd.c -o textlcd.o

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
