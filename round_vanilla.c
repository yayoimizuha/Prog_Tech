#include <stdio.h>

#define LONG_LONG_MAX 0x7fffffffffffffffLL

double round_down(double x, int order);

double round_up(double x, int order);

double round_off(double x, int order);

double even_round(double x, int order);

double ten_n(int k);

int main(void) {
    for (double i = 0; i < 0.02; i += 0.0004) {
        printf("%f\t%f\n", i, round_down(i, -3));
    }

    printf("\n\n\n");
    for (double i = 0; i < 0.02; i += 0.0004) {
        printf("%f\t%f\n", i, round_up(i, -3));
    }

    printf("\n\n\n");
    for (double i = 0; i < 0.02; i += 0.0004) {
        printf("%f\t%f\n", i, round_off(i, -3));
    }

    printf("\n\n\n");
    for (double i = 0; i < 0.02; i += 0.0004) {
        printf("%f\t%f\n", i, even_round(i, -3));
    }

    printf("\n\n\nŒ³‚Ì”\t\tØ‚èŽÌ‚Ä\tØ‚èã‚°\tŽlŽÌŒÜ“ü\t‹ô”ŠÛ‚ß\n");
    for (double i = 0; i < 0.02; i += 0.0004) {
        printf("%f\t%f\t%f\t%f\t%f\n", i, round_down(i, -3), round_up(i, -3), round_off(i, -3), even_round(i, -3));
    }
    return 0;
}

double ten_n(int k) {

    double return_num = 1;
    if (k > 0) {
        //0‚æ‚è‘å‚«‚¢
        for (int i = 0; i < k; ++i) {
            return_num *= 10;
        }
    } else if (k == 0) {
        //0‚Ì‚Æ‚«
        return_num = 1;
    } else if (k < 0) {
        //0‚æ‚è‘å‚«‚¢
        for (int i = 0; i > k; --i) {
            return_num *= 0.1;
        }
    }
    return return_num;
}

double round_down(double x, int order) {
    return (int) (x / ten_n(order)) * ten_n(order);
}

double round_up(double x, int order) {
    return (int) ((x + ten_n(order) - (1.0 / LONG_LONG_MAX)) / ten_n(order)) * ten_n(order);
}

double round_off(double x, int order) {
    return (int) ((x + 5 * ten_n(order - 1)) / ten_n(order)) * ten_n(order);
}

double even_round(double x, int order) {
    x /= 2;
    return (int) ((x + 5 * ten_n(order - 1)) / ten_n(order)) * ten_n(order) * 2;

}