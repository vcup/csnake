#ifndef _SNAKE_H_
#define _SNAKE_H_

// 定义了贪吃蛇游戏的蛇的接口部分
#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'

struct snake {
    struct node *head;
    struct node *tail;
    char way;
    int len;
    int score;
};

struct node {
    struct node *prev;
    struct node *next;
    int x;
    int y;
};

typedef struct snake snake;
typedef struct node node;

snake *init_snake(int x, int y);              // 初始化一条蛇
snake *move_snake(snake *hebi);               // 使蛇向给定方向移动
void add_score(snake *hebi, int score); // 加分
void sub_score(snake *hebi, int score); // 减分
void remove_snake(snake *hebi);         // 回收蛇
int expand_snake(snake *hebi);          // 增长蛇
int short_snake(snake *hebi);           // 缩短蛇

node *add_node(int x, int y, node *prev_node, node *next_node); // 添加节点
void del_node(node *node); // 删除节点

#endif
