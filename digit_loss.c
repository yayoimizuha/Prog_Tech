//
// Created by tomokazu on 2022/06/06.
//
#include <stdio.h>
#include <math.h>

#define H 0.01
#define N 1e2

int main(void) {
    double x, y;
    for (int i = 0; i < N; ++i) {
        x = (1 / (N * 1000000)) * i;
        printf("%.20f\t", x);
        printf("%.20f\t", sqrt(1 + x) - 1);
        printf("%.20f\t", x / (sqrt(1 + x) + 1));
        printf("%.20f\n", (x / (sqrt(1 + x) + 1)) - (sqrt(1 + x) - 1));
    }

    printf("\n\n\n\n\n");

    for (int i = 0; i < N; ++i) {
        x = (1 / (N * 100)) * i;
        y = (1 / (N * 100)) * i * 3;
        printf("%.20f\t", x);
        printf("%.20f\t", log(x) - log(y));
        printf("%.20f\t", log(x / y));
        printf("%.20f\n", (log(x) - log(y)) - log(x / y));
    }

    printf("\n\n\n\n\n");

    for (int i = 0; i < N; ++i) {
        x = (1 / (N * 100)) * i;
        printf("%.20f\t", x);
        printf("%.20f\t", sin(x + H) - sin(x));
        printf("%.20f\t", H * cos(x));
        printf("%.20f\n", sin(x + H) - sin(x) - H * cos(x));
    }

}