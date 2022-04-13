//
// Created by tomokazu on 2022/04/11.
//

#include <stdio.h>

void collatz(int n) {
    while (n != 1) {
        //printf("%d\n", n);
        if (n & 1) {
            n *= 3;
            n++;
        } else {
            n = n >> 1;
        }
    }
    //printf("%d", n);
}

int main(void) {
    int n;
    printf("自然数を入力: ");
    //scanf("%d", &n);
    n = 27345;
    for (int i = 0; i < 10000000; ++i) {
        collatz(n);
    }
    printf("...End.\n");
    return 0;
}