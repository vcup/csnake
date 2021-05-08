#ifndef _FOOD_H_
#define _FOOD_H_
#include "snake.h"

#define SCORE_LEVEL 3

struct dish {
    int sum;
    int cols;
    int rows;
    struct food *first;
    struct food *last;
};
struct food {
    struct food *prev_food;
    struct food *next_food;
    int x;
    int y;
    int score;
};
typedef struct dish dish;
typedef struct food food;

dish *init_dish(int cols, int rows);
void add_food(dish *sara);
food *gen_food(food *prev_food,food *next_food, int x, int y, int score);
void del_food(dish *sara, food *gohan);
int eaten_food(snake *hebi, dish *sara);
void remove_dish(dish *sara);

#endif
