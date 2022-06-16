// pro06.c �i�����ɂ�float�^���g�p���邱�Ɓj
#include <stdio.h>
#include <limits.h>

float sum1(unsigned int n, float a) {
    unsigned int i;
    float s;

    s = 1;

    for (i = 0; i < n; i++) {
        s = s + a;
    };
    return s;
}

float sum2(int n, float a) {
    unsigned int i;
    float r1, r2, s1, s2, t;

    r1 = r2 = 0;
    s1 = s2 = 1;        // s �͘a, r �͐ςݎc��
    // ����ȉ��̂��炭���\��
    for (i = 0; i < n; i++) {
        r2 = r1 + a;
        s2 = s1 + r2;
        t = s2 - s1;
        r1 = r2 - t;
        s1 = s2;
    }
    return s2;
}

int main(void) {
    unsigned int n;
    float a;

    n = INT_MAX;
    a = 1.0 / n;
    printf("1 ��1/%d ��%d�񑫂��Z����\n", n, n);
    printf("1/%d = %.20lf\n", n, 1.0 / n);
    printf("���@1: %.20lf\n", sum1(n, a));
    printf("���@2: %.20lf\n", sum2(n, a));
    return 0;
}
