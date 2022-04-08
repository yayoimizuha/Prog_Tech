// pro01.c
#include <stdio.h>

int main(void) {
    int a, b;
    a = 7123;
    b = 34323;
    printf("交換前：a=%d, b=%d\n", a, b);

    a += b;
    b = a - b;
    a -= b;


    printf("交換後：a=%d, b=%d\n", a, b);
    return 0;
}
