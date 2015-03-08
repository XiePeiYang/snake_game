//////////////////////////////////
//created at 2015.3.6 by Yang
//////////////////////////////////
#include<stdlib.h>
#include"snake.h"
#include"common.h"

void add(unsigned char snake[8],unsigned char x,unsigned char y)
{
	if(eat(snake,x,y))
		fail();
	else
		snake[y] |= 1 << x;	
}

void remove(unsigned char snake[8],unsigned char* x_tail,unsigned char* y_tail,unsigned char direction)
{
	snake[*x_tail] &= ~(1 << *y_tail);
	switch(direction)
	{
		case 1: if((*y_tail) == 7)
					*y_tail = 0;
				else
			   		(*y_tail)++;
				break;
		case 2: if((*y_tail) == 0)
					*y_tail = 7;
				else
					(*y_tail)--;
				break;
		case 3: if((*x_tail) == 0)
					*x_tail = 7;
				else
					(*x_tail)--;
				break;
		case 4: if((*x_tail) == 7)
					*x_tail = 0;
				else
					(*x_tail)++;
				break;
	}	
}

void get_food(unsigned char* x,unsigned char* y)
{
	*x = rand()%7;
	*y = rand()%7;	
}

int eat(const unsigned char snake[8],const unsigned char x,const unsigned char y)
{
	unsigned char j = snake[y] & (1 << x);
	if(j == (1 << x))
		return 1;
	else
		return 0;
}

void fail()
{
	unsigned char fail_word[8] = {0,0,32,0,24,36,0,0};
	while(1)
		light(fail_word,2,2);
}

