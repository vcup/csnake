#include <assert.h>
#include <curses.h>
#include <stddef.h>
#include <stdio.h>
#include "food.h"
#include "snake.h"
#include "painter.h"

int main(void) {
    const int x = 50, y = 20;
    snake *hebi = init_snake(x, y);
    add_score(hebi, 50);
    add_score(hebi, -25);
    assert(hebi->score == 25);

    sub_score(hebi, 25);
    assert(hebi->score == 0);
    
    expand_snake(hebi);
    assert(hebi->tail->x == x);
    assert(hebi->tail->y == y - 1);

    hebi->way = LEFT;
    expand_snake(hebi);
    assert(hebi->tail->x == x + 1);
    assert(hebi->tail->y == y - 1);
    assert(hebi->len == 3); // the snake lenght = 3

    move_snake(hebi);
    assert(hebi->head->x == x-1);
    assert(hebi->head->y == y);
    assert(hebi->tail->x == x);
    assert(hebi->tail->y == y-1);
    // head in x - 1, y; tail in x, y - 1;

    short_snake(hebi);
    assert(hebi->tail->x == x);
    assert(hebi->tail->y == y);
    assert(hebi->len == 2);
    // tail in x, y; lenght is 2

    /////////////////////////////////////////////

    dish *sara = init_dish(hebi); // <- hebi->tail->x value ???
    add_food(sara);
    sara->last_food = gen_food(sara->first_food, NULL, x-1, y, 100); // add a food in sara;food in x-1, y
    sara->sum++;
    eaten_food(hebi, sara);
    assert(hebi->score == 100);
    assert(sara->first_food == sara->last_food);

    add_food(sara);
    assert(sara->sum == 2);

    initscr();
    painter(hebi, sara);
    endwin();
    return 0;
}

