#include "snake.h"
#include <stddef.h>
#include <stdlib.h>

snake *init_snake(int x, int y) {
    snake *hebi = (snake *) malloc(sizeof(snake));
    node *body = add_node(x, y, NULL, NULL);

    hebi->tail = hebi->head = body;
    hebi->score = 0;
    hebi->len = 1;
    hebi->way = UP;
    return hebi;
}
void move_xy(int *x, int *y, char way) {
    switch (way) {
        case UP:
            *y -= 1;
            break;
        case DOWN:
            *y += 1;
            break;
        case LEFT:
            *x -= 1;
            break;
        case RIGHT:
            *x += 1;
            break;
        default:
            exit(1);
    }
    return;
}
snake *move_snake(snake *hebi) {
    int x = hebi->head->x;
    int y = hebi->head->y;
    move_xy(&x, &y, hebi->way);
    node *new_node = add_node(x, y, NULL, hebi->head);
    hebi->head = new_node;
    if (hebi->tail->prev)
        hebi->tail = hebi->tail->prev;
    del_node(hebi->tail->next);
    return hebi;
}
void add_score(snake *hebi, int score) {
    hebi->score += score;
    return;
}
void sub_score(snake *hebi, int score) {
    hebi->score -= score;
    return;
}
void remove_snake(snake *hebi) {
    for (node *body = hebi->head; body->next != NULL; body = body->next) free(body);
    free(hebi);
    return;
}
int expand_snake(snake *hebi) {
    int x = -hebi->tail->x;
    int y = -hebi->tail->y;
    move_xy(&x, &y, hebi->way);
    node *new_node = add_node(-x, -y, hebi->tail, NULL);
    hebi->tail = new_node;
    return ++hebi->len;
}
int short_snake(snake *hebi) {
    hebi->tail = hebi->tail->next;
    del_node(hebi->tail->prev);
    return --hebi->len;
}
node *add_node(int x, int y, node *prev_node, node *next_node) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->x = x;
    new_node->y = y;
    new_node->prev = prev_node;
    if (prev_node)
        prev_node->next = new_node;
    if (next_node)
        next_node->prev = new_node;
    new_node->next = next_node;
    return new_node;
}
void del_node(node *node) {
    if (node->prev)
        node->prev->next = node->next;
    else if (node->next)
        node->next->prev = node->prev;
    free(node);
    return;
}

