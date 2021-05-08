#include "food.h"
#include <stddef.h>
#include <stdlib.h>

dish *init_dish(int cols, int rows) {
    dish *sara = (dish *) malloc(sizeof(dish));
    sara->first = gen_food(NULL, sara->last, -1, -1, 0);
    sara->last = gen_food(sara->first, NULL, -1, -1, 0);
    sara->cols = cols;
    sara->rows = rows;
    sara->sum = 0;
    return sara;
}
void add_food(dish *sara) {
    int x = rand() % sara->cols;
    int y = rand() % sara->rows;
    int score = rand() % SCORE_LEVEL;
    x++; y++; score++;
    sara->last->prev_food = gen_food(sara->last->prev_food, sara->last, x, y, score);
    sara->sum++;
    return;
}
food *gen_food(food *prev_food, food *next_food, int x, int y, int score) {
    food *new_food = (food *) malloc(sizeof(food));
    new_food->x = x;
    new_food->y = y;
    new_food->score = score;
    new_food->next_food = next_food;
    new_food->prev_food = prev_food;
    if (prev_food) prev_food->next_food = new_food;
    if (next_food) next_food->prev_food = new_food;
    return new_food;
}
void del_food(dish *sara, food *gohan) {
    gohan->next_food->prev_food = gohan->prev_food;
    gohan->prev_food->next_food = gohan->next_food;
    free(gohan);
    sara->sum--;
    return;
}
int eaten_food(snake *hebi, dish *sara) {
    int sx = hebi->head->x;
    int sy = hebi->head->y;
    int fx = sara->first->x;
    int fy = sara->first->y;
    food *gohan = sara->first;
    while (!(sx == fx && sy == fy)) {
        // if next_food is NULL, endcall func
        if (!(gohan = gohan->next_food))return 0;
        fx = gohan->x % sara->cols;
        fy = gohan->y % sara->rows;
    } // get food
    int score = gohan->score;
    hebi->score += score;
    del_food(sara, gohan);
    return score;
}

void remove_dish(dish *sara) {
    free(sara);
    return;
}

