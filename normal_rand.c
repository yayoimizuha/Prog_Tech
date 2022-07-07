//
// Created by tomokazu on 2022/06/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUM 1e+7    //������
#define RAND_RANGE 1000

#define GNUPLOT_PATH "C:\\Progra~1\\gnuplot\\bin\\gnuplot.exe -persist"
#define RAND_AVE 70

int main(int argc, char *argv[]) {
    srand(time(NULL)); //�����̏�����(�����ŏ��������Ď��s���ɈႤ�l�ɂȂ�悤�ɂ���B)

    FILE *fp1, *gnuplot;
    int i;
    int x, y;

    int *hist_normal = (int *) malloc(sizeof(int) * (RAND_MAX * RAND_AVE * 2 + 10));
    int *hist_uniform = (int *) malloc(sizeof(int) * (RAND_MAX * RAND_AVE * 2 + 10));

    for (int j = 0; j < RAND_MAX * 12 + 10; ++j) {
        hist_normal[j] = 0;
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

    if ((gnuplot = popen(GNUPLOT_PATH, "w")) == NULL) {
        fprintf(stderr, "Cannot execute gnuplot. Please check file location.\n");
        fprintf(stderr, GNUPLOT_PATH);
        exit(1);
    }

    fprintf(gnuplot, "set terminal windows color\n");
    fprintf(gnuplot, "set title '���K����'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set y2tics\n");
    fprintf(gnuplot, "set y2range [-20:]\n");
    fprintf(gnuplot, "set ylabel '�����̕��z(�U�z�})'\n");
    fprintf(gnuplot, "set y2label '�����̕��z(�܂��)'\n");
    fprintf(gnuplot, "set size square\n");
    fprintf(gnuplot,
            "plot [-1e6:1e6] [-1e6:1e6]  "
            "'-' using 2:3 axis x1y1 with p pointtype 7 linecolor rgb 0x80FF0000 pointsize 0.08 title '�����̕��z(�U�z�})',"
            "'-' using 1:2 axis x1y2 with l linecolor 'blue' linewidth 4 title '�����̕��z(�܂��)'\n");

    //�����̕��ϒl���擾
    int g = 0;
    for (int j = 0; j < 1e3; ++j) {
        g += rand();
    }
    int average = g / 1e3;
    printf("%d\t%ld\t%ld\n", g, average / 1e3, RAND_MAX);


    for (i = 0; i < NUM; i++) {
        x = 0;
        y = 0;

        for (int j = 0; j < RAND_AVE * 2; j++) {
            x += rand();
        }
        hist_normal[x]++;
        x -= RAND_MAX * RAND_AVE;
        for (int j = 0; j < RAND_AVE * 2; j++) {
            y += rand();
        }
        y -= RAND_MAX * RAND_AVE;


        if (i % 100 == 0) { //�v���b�g����ɂ͑�������̂�100��Ɉ�񂾂��B
            fprintf(gnuplot, "%d\t%ld\t%ld\n", i, x, y);
        }
        // ���łɃt�@�C���ɂ��ۑ��B
        fprintf(fp1, "%d\t%ld\t%ld\n", i, x, y);

    }

    fprintf(gnuplot, "e\n");// ��x�f�[�^�̓��͂��I�������Ƃ�`����B

    // RAND_RANGE���Ƃɓ_��ł��ƂŊ��炩�Ȑ܂���O���t�ɂ���B
    int temp_x, temp_y;
    for (int j = 0; j < RAND_MAX * RAND_AVE * 2 + 10; ++j) {
        if (j % RAND_RANGE == 0)temp_x = temp_y = 0;
        temp_x += hist_normal[j];
        if (j % RAND_RANGE == RAND_RANGE - 1) {
            fprintf(gnuplot, "%d\t%ld\t%ld\n", j - RAND_MAX * RAND_AVE, temp_x, temp_y);
        }
    }
    fprintf(gnuplot, "e\n");
    pclose(gnuplot);
    fclose(fp1);


    return 0;
}
