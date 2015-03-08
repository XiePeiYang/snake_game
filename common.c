/////////////////////////////////
// created at 2015.3.6 by Yang
////////////////////////////////
#include<reg51.h>
#include<intrins.h>
#include "common.h"

#define GPIO_KEY P1
#define COMMONPORTS P0

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

unsigned char code TAB[8]  = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

void delay(unsigned int time)
{
  unsigned int i,j;
  for(i=0;i<time;i++)
    for(j=0;j<121;j++);
}

void Hc595SendByte(unsigned char dat)
{
	unsigned char a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}

void light(const unsigned char *body,unsigned char x,unsigned char y)
{	
 	unsigned char tab,j;
	for(j=0;j<20;j++)
	{	
		for(tab=0;tab<8;tab++)
		{	
			Hc595SendByte(0x00);			     															
			COMMONPORTS	= TAB[tab];				 
			Hc595SendByte(body[tab]);	
			delay(2);		
		}
		Hc595SendByte(0x00);			     															
		COMMONPORTS	= TAB[y];				 
		Hc595SendByte(1 << x);	
		delay(2);
	}
}

b_value button()
{
	unsigned char KeyValue = 6;
	b_value re = none;	
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)
	{
		delay(38);
		if(GPIO_KEY!=0x0f)
		{
			
			//²âÊÔÁÐ
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//²âÊÔÐÐ
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))	 
			{
				delay(38);
				a++;
			}
		}
	}
	switch(KeyValue)
	{
		case 0:re = up;break;
		case 1:re = down;break;
		case 2:re = right;break;
		case 3:re = left;break;
		case 4:re = ok;break;
		case 5:re = cancel;break;
		default:re = none;
	}
	return re;
}
