//
// Created by tomokazu on 2022/06/14
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    int a;
    fp1 = fopen("file1", "rt");
    fp2 = fopen("file2", "wt");
    fscanf(fp1, "%d", &a);
    printf("%d\n", a);
}