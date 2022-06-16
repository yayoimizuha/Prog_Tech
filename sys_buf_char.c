//
// Created by tomokazu on 2022/05/11.
//
#include <stdio.h>
#include <unistd.h>

int main(void) {
    int c;
    while ((c = getchar()) >= 0) {
        putchar(c);
    }
    return 0;
}
