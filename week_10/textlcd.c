#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "textlcd.h"
#include <sys/msg.h>
#include <pthread.h>

#define TEXTLCD_DRIVER_NAME "/dev/peritextlcd"
stTextLCD stlcd;

int lcdtextwrite(const char *str1 , const char *str2, int lineFlag)
{
	unsigned int linenum = 0;
	
	int fd;
	int len;
	memset(&stlcd,0,sizeof(stTextLCD));

	if(lineFlag ==1)
	{
		stlcd.cmdData = CMD_DATA_WRITE_LINE_1;
		len = strlen(str1);
		if(len > COLUMN_NUM)
		{
			memcpy(stlcd.TextData[stlcd.cmdData-1],str1,COLUMN_NUM);
		}
		else
		{
			memcpy(stlcd.TextData[stlcd.cmdData-1],str1,len);
		}
	}
	else if(lineFlag == 2)
	{
		stlcd.cmdData = CMD_DATA_WRITE_LINE_2;
		len = strlen(str2);
		if(len > COLUMN_NUM)
		{
			memcpy(stlcd.TextData[stlcd.cmdData-1],str2,COLUMN_NUM);
		}
		else
		{
			memcpy(stlcd.TextData[stlcd.cmdData-1],str2,len);
		}
	}
	else
	{
		printf("lineFlag error\n");
		return -1;
	}
	stlcd.cmd = CMD_WRITE_STRING;

	fd = open(TEXTLCD_DRIVER_NAME,O_RDWR);
	if(fd < 0)
	{
		printf("node open error.\n");
		return -1;
	}
	write(fd,&stlcd,sizeof(stTextLCD));
	close(fd);
	return 0;

}
