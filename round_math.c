#include <stdio.h>
#include <math.h>

#define INT_MAX 2147483647

double round_down(double x);

double round_up(double x);

double round_off(double x);

double even_round(double x);

double ten_n(int k);

int main(void) {
    printf("\n\n\n���̐�\t\t�؂�̂�\t�؂�グ\t�l�̌ܓ�\t�����ۂ�\n");
    for (double i = 0; i < 20; i += (2.0 / 3)) {
        printf("%f\t%f\t%f\t%f\t%f\n", i, round_down(i), round_up(i), round_off(i), even_round(i));
    }
    return 0;
}


double round_down(double x) {
    return floor(x);
}

double round_up(double x) {
    return floor(x + 1 - (1.0 / INT_MAX));
}

double round_off(double x) {
    return round(x);
}

double even_round(double x) {
    return round(x / 2) * 2;
}