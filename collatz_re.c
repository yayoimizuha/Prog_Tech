//
// Created by tomokazu on 2022/04/11.
//

#include <stdio.h>

void collatz(int n);


int main(void) {
    int n;
    printf("自然数を入力: ");
    //scanf("%d", &n);
    n = 27345;
    collatz(n);
    printf("...End.\n");
    return 0;
}


void collatz(int n) {
    printf("%d\n", n);
    if (n == 1)return;
    if (n % 2) {
        collatz(n * 3 + 1);
    } else {
        collatz(n / 2);
    }
}