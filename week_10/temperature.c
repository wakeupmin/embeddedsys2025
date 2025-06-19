#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include "temperature.h"

// SPI 통신을 위한 전역 변수
static char gbuf[10];
static int file;
static const char *device = "/dev/spidev1.0";


int spi_init(char filename[40]) {
    __u8 mode, lsb, bits;
    __u32 speed = 20000;

    if ((file = open(filename, O_RDWR)) < 0) {
        printf("Failed to open the bus. ErrorType: %d\n", errno);
        exit(1);
    }

    if (ioctl(file, SPI_IOC_RD_MODE, &mode) < 0) {
        perror("SPI rd_mode");
        return -1;
    }
    if (ioctl(file, SPI_IOC_RD_LSB_FIRST, &lsb) < 0) {
        perror("SPI rd_lsb_first");
        return -1;
    }
    if (ioctl(file, SPI_IOC_RD_BITS_PER_WORD, &bits) < 0) {
        perror("SPI bits_per_word");
        return -1;
    }

    printf("%s: spi mode %d, %d bits %sper word, %d Hz max\n",
           filename, mode, bits, lsb ? "(lsb first)" : "", speed);

    return file;
}


char *spi_read_lm74(int file) {
    int len;
    memset(gbuf, 0, sizeof(gbuf));
    len = read(file, gbuf, 2); 
    if (len != 2) {
        perror("read error");
        return NULL;
    }
    return gbuf;
}


void spi_exit(void) {
    close(file);
}

// 온도를 계산하여 반환
double getTemperature(void) {
    char *buffer;
   
    spi_init((char*)device);
    buffer = (char *)spi_read_lm74(file);
    spi_exit();

    if (buffer == NULL) {
        printf("temp buffer error!\n");
        return -1; 
    }

    int value = 0;
    value = (buffer[1] >> 3);    
    value = (value & 0x1F) | ((buffer[0]) << 5);   

    // if buffer[0] MSB is < 0, minus temperature.
    if (buffer[0] & 0x80) {
        int i = 0;
        for (i = 31; i > 12; i--) {
            value |= (1 << i);
        }
    }

    //  0.0625 degrees per 1bit
    double temp = (double)value * 0.0625;
    printf("Current Temp: %lf\n", temp);
    return temp;
}

