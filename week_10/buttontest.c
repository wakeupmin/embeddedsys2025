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
#include <sys/msg.h>
#include <pthread.h>
#include "button.h"

static int msgID;

int main(void)
{
    BUTTON_MSG_T messageRxData;
    int msdID = msgget(MESSAGE_ID,IPC_CREAT | 0666);
    buttonInit();

    while(1)
    {
        msgrcv(msgID,&rmessageRxData.keyInput,sizeof(messageRxData.keyInput),0,0);
        switch(messageRxData.keyInput)
        {
            case KEY_VOLUMEUP
        }
    }
}