#include <stdio.h>
#include <stdlib.h>
#include "button.h"



#define INPUT_DEVICE_LIST "/dev/input/event"
#define PROBE_FILE "/proc/bus/input/devices"
#define HAVE_TO_FIND_1 "N: Name=\"ecube-button\"\n"
#define HAVE_TO_FIND_2 "H: Handlers=kbd event"

static int fd = 0;
static int msgID = 0;
char inputDevPath[200] = {0,};
static pthread_t buttonTh_id;
BUTTON_MSG_T messageTxData;
static int thread_ext; //ptrhead exit flag
static int 

int buttonInit(void)
{
    thread_ext = 0;
    if (probeButtonPath(inputDevPath) == 0)
    {
        printf ("ERROR! File Not Found!\r\n");
        printf ("Did you insmod?\r\n");
        return 0;
    }
    printf("inputDevPath:%s\r\n", inputDevPath);
    fd = open(inputDevPath, O_RDONLY);
    msgID = msgget(MESSAGE_ID, IPC_CREAT|0666);
    pthread_create(&buttonTh_id, NULL, buttonThFunc, NULL);
    return msgID;
}

int probeButtonPath(char *newPath)
{
    int returnValue = 0;
    int number = 0;
    FILE *fp = fopen(PROBE_FILE,"rt");
    while(!feof(fp)) 
    {
        char tmpStr[200];
        fgets(tmpStr,200,fp);
        if (strcmp(tmpStr,HAVE_TO_FIND_1) == 0)
        {
            printf("YES! I found!: %s\r\n", tmpStr);
            returnValue = 1;
        }
        if ((returnValue == 1) && (strncasecmp(tmpStr, HAVE_TO_FIND_2, strlen(HAVE_TO_FIND_2)) == 0))
        {
            printf ("-->%s",tmpStr);
            printf("\t%c\r\n",tmpStr[strlen(tmpStr)-3]);
            number = tmpStr[strlen(tmpStr)-3] - '0'; 
            break;
        }
    }
    fclose(fp);
    if (returnValue == 1)   sprintf (newPath,"%s%d",INPUT_DEVICE_LIST,number);
    return returnValue;
}

void* buttonThFunc(void *arg)
{
    messageTxData.messageNum = 1;
    struct input_event stEvent;
    while (!thread_ext)
    {
        read(fd, &stEvent, sizeof(stEvent));
        if (stEvent.type == EV_KEY)
        {
            messageTxData.keyInput = stEvent.code; //which key
            messageTxData.pressed = stEvent.value; //pressed, unpressed
            if(msgsnd(msgID, &messageTxData, sizeof(messageTxData)-sizeof(messageTxData.messageNum), 0)==-1)
            {
                printf("btn msgsnd failed\n");
            }
        }
    }
}

int buttonExit(void)
{
    thread_ext = 1;
    pthread_join(buttonTh_id,NULL);
    close(fd);
}

