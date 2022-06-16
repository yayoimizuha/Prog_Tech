//
// Created by tomokazu on 2022/06/03.
//
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 1000000000
#define CHAR_BIT 8

double calc(long long int n);

void print_b(unsigned int v);


int main(void) {
#pragma omp parallel for
    for (long long int i = 0; i < N; i++) {
        if (calc(i) == 1.0) {
            printf("%d\t%#o\t", i, i);
            print_b(i);
            printf("\t%.20lf", log2(i));
            if (fmod(log2(i), 1.0) != 0.0) {
                printf(" *");
            }
            printf("\n");
        } else {
            //printf("False\n");
        }
    }
    return 0;
}

double calc(long long int n) {
    double x = 1.0 / n, sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += x;
    }
    return sum;
}

void print_b(unsigned int v) {
    unsigned int mask = (int) 1 << (sizeof(v) * CHAR_BIT - 1);
    do putchar(mask & v ? '1' : '0');
    while (mask >>= 1);
}

