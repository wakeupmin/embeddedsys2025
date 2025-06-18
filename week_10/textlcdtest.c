#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/msg.h>
#include <pthread.h>
#include "textlcd.h"

void doHelp(void){
    printf("usage: textlcdtest <linenum> <'string'>\n");
    printf(" linenum => 1~2\n");
    printf(" ex) textlcdtest 2 'test hello'\n");
}

int main(int argc, char **argv)
{
    unsigned int linenum = 0;
    stTextLCD stlcd;
    int fd;
    memset(&stlcd, 0, sizeof(stTextLCD));

    if (argc > 3)
    {
        perror(" Arg number is less than 2 \n");
        doHelp();
        return -1;
    }

    linenum = strtol(argv[1], NULL, 10);
    printf("linenum: %d \n", linenum);
    switch(linenum)
    {
        case 1:
                lcdtextwrite(argv[2],NULL,linenum);
                break;
        case 2:
                lcdtextwrite(NULL,argv[2],linenum);
                break;

    }
    return 0;
}
