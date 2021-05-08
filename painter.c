#include <stddef.h>
#include <curses.h>
#include "painter.h"
#include "snake.h"
#include "food.h"

void painter(snake *hebi, dish *sara) {
    clear();
    box(stdscr, ACS_VLINE, ACS_HLINE);
    paint_dish(sara);
    paint_snake(hebi);
    move(sara->rows/2, sara->cols/2);
    refresh();
}

void paint_dish(dish *sara) {
    food *gohan = sara->first;
    while (gohan != sara->last) {
        mvaddch(gohan->y % LINES, gohan->x % COLS, FOOD_SYMBOL(gohan->score));
        gohan = gohan->next_food;
    }
    return;
}

char snake_head_symbol(char way) {
    switch (way) {
        case UP:
            return SH_U;
        case DOWN:
            return SH_D;
        case LEFT:
            return SH_L;
        case RIGHT:
            return SH_R;
        default:
            return '\0';
    }
}
void paint_snake(snake *hebi) {
    mvaddch(hebi->head->y, hebi->head->x, snake_head_symbol(hebi->way));
    node *body = hebi->head->next;
    while (body) {
        mvaddch(body->y, body->x, SH_B);
        body = body->next;
    }
    return;
}

