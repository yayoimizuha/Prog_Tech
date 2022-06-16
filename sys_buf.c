//
// Created by tomokazu on 2022/05/11.
//
#include <stdio.h>
#include <unistd.h>

#define N 1

int main(void) {
    int n;
    char buf[N];
    while ((n = read(0, buf, N)) > 0) {
        write(1, buf, n);
    }
    return 0;
}
