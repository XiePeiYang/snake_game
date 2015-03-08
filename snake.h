///////////////////////////////
//created at 2015.3.7 by Yang
//////////////////////////////

#ifndef _SNAKE_H_
#define _SNAKE_H_

void add(unsigned char snake[8],unsigned char x,unsigned char y);

void remove(unsigned char snake[8],unsigned char* x_tail,unsigned char* y_tail,unsigned char direction);

void get_food(unsigned char* x,unsigned char* y);

int eat(const unsigned char snake[8],const unsigned char x,const unsigned char y); 

void fail();

#endif
