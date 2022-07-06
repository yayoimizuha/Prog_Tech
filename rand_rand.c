//
// Created by tomokazu on 2022/06/24.
//

#include <stdio.h>
#include <stdlib.h>

#define NUM    1e+4    //生成数
#define A 9
#define C 13
#define M 4096

unsigned int lcgs(unsigned int x) {
    unsigned int y;
    y = (A * x + C) % M;
    return y;
}

int main(int argc, char *argv[]) {
    FILE *fp1;
    int i;
    unsigned int x, y;
    printf("%d\n", argc);

    // Usage
    if (argc != 2) {
        fprintf(stderr, "Usage: ./a.out file1\n");
        exit(1);
    }

    // File Open
    if ((fp1 = fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "File open error 1\n");
        exit(1);
    }

    x = 0;
    y = 1;
    for (i = 0; i < NUM; i++) {
        x = rand();
        y = rand();
        fprintf(fp1, "%d %u %u\n", i, x, y);
    }


    return 0;
}
