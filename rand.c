//
// Created by tomokazu on 2022/06/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define NUM    1e+4    //生成数
#define A 9
#define C 13
#define M 4096

#define GNUPLOT_PATH "C:\\Progra~1\\gnuplot\\bin\\gnuplot.exe -persist"

unsigned int lcgs(unsigned int x) {
    unsigned int y;
    y = (A * x + C) % M;
    return y;
}

int main(int argc, char *argv[]) {
    FILE *fp1, *gnuplot;
    int i;
    unsigned long x, y;

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

    gnuplot = popen(GNUPLOT_PATH, "w");

    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set size square\n");
    fprintf(gnuplot, "plot [-4000:37000] [-4000:37000] '-' using 2:3 with lp pointtype 7 linecolor 'turquoise'\n");
    x = 0;
    y = 1;
    for (i = 0; i < NUM; i++) {
        //x = lcgs(x);
        //y = lcgs(y);
        x = rand();
        y = rand();
        fprintf(fp1, "%u\t%u\n", x, y);
        fprintf(gnuplot, "%d\t%u\t%u\n", i, x, y);

    }

    fprintf(gnuplot, "e\n");
    pclose(gnuplot);

    return 0;
}
