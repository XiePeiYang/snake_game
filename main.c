//////////////////////////////////////
//created at 2015.3.7 by Yang
/////////////////////////////////////
#include<reg51.h>
#include "common.h"
#include "snake.h"

void main()
{
	while(1)
	{
		unsigned char snake[8] = {0};
		unsigned char x_head = 0,y_head = 0;
		unsigned char x_tail = 0,y_tail = 0;
		unsigned char dire[64] = {0};
		unsigned dire_i = 0,dire_del = 0;
		b_value now_b = none,prev_b = right;
		unsigned char food_x,food_y;
		while(1)
		{
			get_food(&food_x,&food_y);
			if(!eat(snake,food_x,food_y))break;
		}

		snake[0] = 1;

		while(1)
		{
			now_b = button();

			if(now_b == ok)
				break;
			if(now_b == left||now_b == right||now_b == up||now_b == down)
				if((now_b == up&&prev_b != down)||(now_b == down&&prev_b != up)||(now_b == left&&prev_b != right)||(now_b == right&&prev_b != left))
					prev_b = now_b;
			switch(prev_b)
			{
				case right: if(x_head == 7)
								x_head = 0;
							else
								x_head++;
							add(snake,x_head,y_head);
							dire[dire_i++] = 1;
							break;
				case left:  if(x_head == 0)
								x_head = 7;
							else
								x_head--;
							add(snake,x_head,y_head);
							dire[dire_i++] = 2;
							break;
				case up:    if(y_head == 0)
								y_head = 7;
							else
								y_head--;
							add(snake,x_head,y_head);
							dire[dire_i++] = 3;
							break;
				case down:  if(y_head == 7)
								y_head = 0;
							else
								y_head++;
							add(snake,x_head,y_head);
							dire[dire_i++] = 4;
							break;
			}

			if(!eat(snake,food_x,food_y))
				remove(snake,&x_tail,&y_tail,dire[dire_del++]);
			else
			{
				while(1)
				{
					get_food(&food_x,&food_y);
					if(!eat(snake,food_x,food_y))break;
				}
			}

			light(snake,food_x,food_y);

			if(dire_i == 64)
				dire_i = 0;
			if((dire_del) == 64)
				dire_del = 0;
		}
	}
}
