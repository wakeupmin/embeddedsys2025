#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "buzzer.h"

#ifndef MAX_SCALE_STEP
#define MAX_SCALE_STEP 8
#endif

int main(void)
{
    printf("Buzzer Test Program\n");

    if (buzzerInit() == 0)
    {
        printf("Buzzer Init Failed!\n");
        return -1;
    }

    printf("Playing diatonic scale (C Major)...\n");

    for (int scale = 1; scale <= MAX_SCALE_STEP; scale++)
    {
        printf("Playing scale %d\n", scale);
        buzzerPlaySong(scale);
        sleep(1);
        buzzerStopSong();
    }

    printf("Finished playing.\n");

    printf("Cleaning up resources...\n");
    buzzerExit();

    printf("Buzzer test finished.\n");

    return 0;
}