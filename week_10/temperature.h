#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

// 함수 프로토타입 선언
int spi_init(char filename[40]);
void spi_exit(void);
char *spi_read_lm74(int file);
double getTemperature(void);

#endif