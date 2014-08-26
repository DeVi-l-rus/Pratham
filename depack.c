#include "ax25.h"

char buf[50];
char temp;

void main()
{
	temp = recieve();
	
	while(1)
	{
		if (temp = '01111110')
		{
			goto decode;
		}
		temp = recieve();
	}
	
	decode:
	do
	{
		temp = recieve();
		
		if (temp == )
	}while(temp != '01111110');
}
