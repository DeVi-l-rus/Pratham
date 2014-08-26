#include "ax25.h"

char address[30];
char message[50];
char AX_CONTROL; char AX_PID;
char temp[256];
char crc[2];
uint_16t crc_act;
int count=0;

void main()
{
	temp[count] = recieve();
	
	while(1)
	{
		if (temp[count] = '01111110')
		{
			count++;
			goto decode;
		}
		temp[count] = recieve();
	}
	
	decode:
	temp[count] = recieve();
	if (temp[count] != '01111110')
	{
		for (int i=0, i<21; i++)
		{
			address[i] = temp[count++];
			temp[count] = recieve();
		}
		
		AX_CONTROL = temp[count++];
		temp[count] = recieve()
		AX_PID = temp[count++];
		
		int i = 0;
		do
		{
			temp[count] = recieve();
			message[i++] = temp[count++];
		}while(temp[count-1]=='01111110');
		
		count--;
		count--;
		crc[1] = temp[count--];
		crc[0] = temp[count--]
		
		crc_act = calculate_crc_16(temp+1, count);
		
		if(strcmp(crc_act, crc))
		{
			cout<< "The recieved code is correct...!!";
		}
		
	}
}
