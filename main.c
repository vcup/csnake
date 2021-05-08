#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "snake.h"
#include "food.h"
#include "painter.h"
#include "operate.h"
#define MANY_CALL_FUNC(func, n, ...) for (int m = 0; m < n; m++) func(__VA_ARGS__)

int main(void) {
    char way = UP;

    initscr();
    snake *hebi = init_snake(COLS/2, LINES/2);
    dish *sara = init_dish(COLS -2, LINES -2);
    box(stdscr, ACS_VLINE, ACS_HLINE);

    int cols = COLS;
    int lines = LINES;

    add_food(sara);
    int score;
    while (way != EOF) {
        score = eaten_food(hebi, sara);
        MANY_CALL_FUNC(expand_snake, score, hebi);
        MANY_CALL_FUNC(add_food, score, sara);
        hebi->way = way;
        move_snake(hebi);
        painter(hebi, sara);
        way = get_way();
    }
    endwin();
    return 0;
}

