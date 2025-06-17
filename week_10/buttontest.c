#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      
#include <sys/ipc.h>     
#include <sys/msg.h>     
#include <linux/input.h> 
#include "button.h"     

int main(void)
{
    int msgID;
    BUTTON_MSG_T messageRxData; 

    printf("Button Test Program\n");

    msgID = buttonInit();
    if (msgID < 0)
    {
        printf("Button Init Failed!\n");
        return -1;
    }

    printf("Button library initialized. Press buttons to test.\n");
    printf("Press 'Back' button to exit.\n");

    while(1)
    {

        int rxResult = msgrcv(msgID, &messageRxData, sizeof(messageRxData) - sizeof(long), 0, 0);
        if (rxResult < 0)
        {
            perror("msgrcv failed");
            break;
        }

   
        printf("Received Message -> Key: %d, Pressed: %d\n", messageRxData.keyInput, messageRxData.pressed);

     
        switch(messageRxData.keyInput)
        {
            case KEY_VOLUMEUP:
                printf("  >> VOLUME UP button ");
                break;
            case KEY_VOLUMEDOWN:
                printf("  >> VOLUME DOWN button ");
                break;
            case KEY_HOME:
                 printf("  >> HOME button ");
                 break;
            case KEY_SEARCH:
                 printf("  >> SEARCH button ");
                 break;
            case KEY_BACK:
                printf("  >> BACK button ");
                break;
            default:
                printf("  >> Unknown button ");
                break;
        }

   
        if (messageRxData.pressed)
        {
            printf("pressed.\n");
        }
        else
        {
            printf("released.\n");
        }
     
        if (messageRxData.keyInput == KEY_BACK && messageRxData.pressed == 0)
        {
            printf("\nExit condition met.\n");
            break; 
        }
    }

    printf("Cleaning up resources...\n");
   

    buttonExit();

    printf("Button test finished.\n");
    return 0;
}