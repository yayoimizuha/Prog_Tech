//
// Created by tomokazu on 2022/06/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define NUM 1e+7    //ê∂ê¨êî
#define A 9
#define C 13
#define M 4096
#define RAND_RANGE 1000

#define GNUPLOT_PATH "C:\\Progra~1\\gnuplot\\bin\\gnuplot.exe -persist"
#define RAND_AVE 70

int main(int argc, char *argv[]) {
    FILE *fp1, *gnuplot;
    int i;
    int x, y;
    int *hist_x = (int *) malloc(sizeof(int) * (RAND_MAX * RAND_AVE * 2 + 10));
    int *hist_y = (int *) malloc(sizeof(int) * (RAND_MAX * RAND_AVE * 2 + 10));
    for (int j = 0; j < RAND_MAX * 12 + 10; ++j) {
        hist_y[j] = hist_x[j] = 0;
    }
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

    fprintf(gnuplot, "set title 'ê≥ãKóêêî'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set y2tics\n");
    fprintf(gnuplot, "set y2range [-20:]\n");
    fprintf(gnuplot, "set ylabel 'óêêîÇÃï™ïz(éUïzê})'\n");
    fprintf(gnuplot, "set y2label 'óêêîÇÃï™ïz(ê‹ÇÍê¸)'\n");
    fprintf(gnuplot, "set output 'test.eps'\n");
    fprintf(gnuplot, "set size square\n");
    fprintf(gnuplot,
            "plot [-1e6:1e6] [-1e6:1e6]  '-' using 2:3 axis x1y1 with p pointtype 7 linecolor rgb 0x80FF0000 pointsize 0.08 title 'óêêîÇÃï™ïz(éUïzê})',"
            " '-' using 1:2 axis x1y2 with l linecolor 'blue' linewidth 4 title 'óêêîÇÃï™ïz(ê‹ÇÍê¸)'\n");
    //  '-' using 2:3 with p pointtype 7 linecolor 'red',
    int g = 0;
    for (int j = 0; j < 1e3; ++j) {
        g += rand();
    }
    int average = g / 1e3;
    printf("%d\t%ld\t%ld\n", g, average / 1e3, RAND_MAX);
    srand(time(NULL));


    for (i = 0; i < NUM; i++) {
        x = 0;
        y = 0;
        //x = lcgs(x);
        //y = lcgs(y);

        for (int j = 0; j < RAND_AVE * 2; j++) {
            x += rand();
        }
        hist_x[x]++;
        //x -= (average / 30);
        x -= RAND_MAX * RAND_AVE;
        for (int j = 0; j < RAND_AVE * 2; j++) {
            y += rand();
        }
        y -= RAND_MAX * RAND_AVE;


        if (i % 100 == 0) { //
            fprintf(gnuplot, "%d\t%ld\t%ld\n", i, x, y);
        }

    }
    fprintf(gnuplot, "e\n");
    int temp_x, temp_y;
    for (int j = 0; j < RAND_MAX * RAND_AVE * 2 + 10; ++j) {
        if (j % RAND_RANGE == 0)temp_x = temp_y = 0;
        //if (hist_x[j] < 2 && hist_y[j] < 2)continue;

        temp_x += hist_x[j];
        // temp_y += hist_y[j];

        if (j % RAND_RANGE == RAND_RANGE - 1) {
            fprintf(gnuplot, "%d\t%ld\t%ld\n", j - RAND_MAX * RAND_AVE, temp_x, temp_y);

        }
        //fprintf(stdout, "%d\t%ld\t%ld\n", j, hist_x[j], hist_y[j]);
    }
    fprintf(gnuplot, "e\n");

    // fprintf(gnuplot, "set autoscale");
    pclose(gnuplot);
    //system("pause");


    return 0;
}
