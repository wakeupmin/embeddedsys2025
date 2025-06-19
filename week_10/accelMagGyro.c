#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "accelMagGyro.h"

#define ACCELPATH "/sys/class/misc/FreescaleAccelerometer/"
#define MAGNEPATH "/sys/class/misc/FreescaleMagnetometer/"
#define GYROPATH "/sys/class/misc/FreescaleGyroscope/"


int getIMU(void) {
    int fd = 0;
    FILE *fp = NULL;

    //(Accelerometer)
    if ((fd = open(ACCELPATH "enable", O_WRONLY)) < 0) {
        perror("Failed to open Accelerometer enable");
        return -1;
    }
    dprintf(fd, "1");
    close(fd);

    if ((fp = fopen(ACCELPATH "data", "rt")) == NULL) {
        perror("Failed to open Accelerometer data");
        return -1;
    }
    int accel[3];
    fscanf(fp, "%d,%d,%d", &accel[0], &accel[1], &accel[2]);
    printf("I read Accel %d, %d, %d\n", accel[0], accel[1], accel[2]);
    fclose(fp);

    // (Magnetometer)
    if ((fd = open(MAGNEPATH "enable", O_WRONLY)) < 0) {
        perror("Failed to open Magnetometer enable");
        return -1;
    }
    dprintf(fd, "1");
    close(fd);

    if ((fp = fopen(MAGNEPATH "data", "rt")) == NULL) {
        perror("Failed to open Magnetometer data");
        return -1;
    }
    int magne[3];
    fscanf(fp, "%d,%d,%d", &magne[0], &magne[1], &magne[2]);
    printf("I read Magneto %d, %d, %d\n", magne[0], magne[1], magne[2]);
    fclose(fp);

    // (Gyroscope)
    if ((fd = open(GYROPATH "enable", O_WRONLY)) < 0) {
        perror("Failed to open Gyroscope enable");
        return -1;
    }
    dprintf(fd, "1");
    close(fd);

    if ((fp = fopen(GYROPATH "data", "rt")) == NULL) {
        perror("Failed to open Gyroscope data");
        return -1;
    }
    int gyro[3];
    fscanf(fp, "%d,%d,%d", &gyro[0], &gyro[1], &gyro[2]);
    printf("I read Gyroscope %d, %d, %d\n", gyro[0], gyro[1], gyro[2]);
    fclose(fp);

    return 0;
}