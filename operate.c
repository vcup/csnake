#include "operate.h"

char char2way(char ch) {
    switch (tolower(ch)) {
        case UP_KEY:
            return UP;
        case DOWN_KEY:
            return DOWN;
        case LEFT_KEY:
            return LEFT;
        case RIGHT_KEY:
            return RIGHT;
        default:
            return EOF;
    }
}

char get_way(void) {
    char way = char2way(getc(stdin));
    if (way == EOF) {
        puts("type again to leave");
        return char2way(getc(stdin));
    }
    return way;
}

