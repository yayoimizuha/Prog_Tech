//
// Created by tomokazu on 2022/06/24.
//

#include <stdio.h>
#include <stdlib.h>

#define NUM    1e+4    //ê∂ê¨êî
#define GNUPLOT_PATH "C:\\Progra~1\\gnuplot\\bin\\gnuplot.exe -persist"

int main(int argc, char *argv[]) {
    FILE *fp1, *gnuplot;

    unsigned long x, y;

    typedef struct {
        unsigned long x;
        unsigned long y;
    } xy;

    xy *rand_arr = malloc(sizeof(xy) * NUM);
    int *rand_hist = calloc(RAND_MAX, sizeof(int));

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

    if ((gnuplot = popen(GNUPLOT_PATH, "w")) == NULL) {
        fprintf(stderr, "Cannot execute gnuplot. Please check file location.\n");
        fprintf(stderr, GNUPLOT_PATH);
        exit(1);
    }
    fprintf(gnuplot, "set terminal windows color\n");
    fprintf(gnuplot, "set title 'rand()ä÷êî'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set y2tics\n");
    fprintf(gnuplot, "set y2range [-2:9]\n");
    fprintf(gnuplot, "set ylabel 'óêêîÇÃï™ïz(éUïzê})'\n");
    fprintf(gnuplot, "set y2label 'óêêîÇÃï™ïz(ê‹ÇÍê¸)'\n");
    fprintf(gnuplot, "set size square\n");
    fprintf(gnuplot,
            "plot [-4000:36767] [-4000:36767] '-' using 2:3 axis x1y1 w l linecolor 'pink' title 'line',"
            " '-' using 2:3 axis x1y1 w p linecolor 'red' pointsize 0.2 pointtype 7 title 'point' ,"
            " '-' using 1:2 axis x1y2 w l lc rgb 0x440000ff title 'hist' \n");
    x = 0;
    y = 1;
    for (int i = 0; i < NUM; i++) {
        rand_arr[i].x = x = rand();
        rand_hist[x]++;
        rand_arr[i].y = y = rand();
        fprintf(fp1, "%u\t%u\n", x, y);
        fprintf(gnuplot, "%d\t%u\t%u\n", i, x, y);

    }
    fprintf(gnuplot, "e\n");

    for (int i = 0; i < NUM; ++i) {
        fprintf(gnuplot, "%d\t%u\t%u\n", i, rand_arr[i].x, rand_arr[i].y);
    }
    fprintf(gnuplot, "e\n");
    for (int i = 0; i < RAND_MAX; ++i) {
        // printf("%d\n", rand_hist[i]);
        fprintf(gnuplot, "%d\t%d\n", i, rand_hist[i]);
    }
    fprintf(gnuplot, "e\n");
    pclose(gnuplot);

    return 0;
}
