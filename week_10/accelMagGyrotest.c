#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "accelMagGyro.h"

int main(void) {
    while(1) {
        getIMU();
        printf("\n");
        sleep(5); 
    }
    return 0;
}