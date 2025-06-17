#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <linux/input.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "led.h"

int main()
{
    ledLibInit();
    for(int i = 0; i < 8 ; i++) //turn on led 0 to 7
    {
        ledOnOff(i,1);
        ledStatus();
    }
        for(int i = 7; i >= 0 ; i--) //turn off led 7 to 0
    {
        ledOnOff(i,0);
        ledStatus();
    }
    return 0;
}
