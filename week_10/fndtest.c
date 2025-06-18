#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      
#include <sys/ipc.h>     
#include <sys/msg.h>     
#include <linux/input.h> 
#include <sys/msg.h>
#include <pthread.h>
#include <fcntl.h>
#include "fnd.h"

int main()
{
    fndInit();
    for(int i =0; i < 8 ; i++)
    {
        fndDisp(123456,1);
        sleep(1);
        fndDisp(011113,2);
        sleep(1);
        fndDisp(250618,4);
        sleep(1);
        fndDisp(250619,8);
        sleep(1);
        fndDisp(250620,16);
        sleep(1);
        fndDisp(405195,32);
        sleep(1);
    }
    fndExit();
    return 0;

}