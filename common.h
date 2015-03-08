/////////////////////////////////////
// Created at 2015.3.6 by Yang
////////////////////////////////////

#ifndef _COMMON_H_
#define _COMMON_H_

typedef enum bvalue{none,ok,cancel,up,down,right,left} b_value;

void delayms(unsigned int time);

b_value button();

void light(const unsigned char *body,unsigned char x,unsigned char y);

#endif