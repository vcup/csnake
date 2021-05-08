#ifndef _PAINTER_H_
#define _PAINTER_H_
#include "snake.h"
#include "food.h"

#define FOOD_SYMBOL_1 'o'
#define FOOD_SYMBOL_2 '0'
#define FOOD_SYMBOL_3 '+'
#define FOOD_SYMBOL(SCORE) SCORE <= 1? FOOD_SYMBOL_1: SCORE <= 2? FOOD_SYMBOL_2: SCORE <= 3?FOOD_SYMBOL_3 : '?'

#define SH_U '^'
#define SH_D 'v'
#define SH_L '<'
#define SH_R '>'
#define SH_B '*'

void painter(snake *hebi, dish *sara);
char snake_head_symbol(char way);
void paint_snake(snake *hebi);
void paint_dish(dish *sara);

#endif
