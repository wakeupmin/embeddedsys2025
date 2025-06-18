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
    for(int i =0; i < 8 ; i++)
    {
        fndDisp(123456,0b000001);
        usleep(500000);
        fndDisp(011113,0b000010);
        usleep(500000);
        fndDisp(250618,0b000100);
        usleep(500000);
        fndDisp(250619,0b001000);
        usleep(500000);
        fndDisp(250620,0b010000);
        usleep(500000);
        fndDisp(405195,0b000100);
        usleep(500000);
    }
    return 0;

}