//
// Created by tomokazu on 2022/04/08.
//

#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LEN 5000

int char_to_int(char C);

int main(void) {

    char *process_string = calloc(LEN, sizeof(char));
    int *num_arr = malloc(sizeof(int) * LEN / 2);
    memset(num_arr, 0, sizeof(int) * LEN / 2);
    process_string = "1 212 3 43 234 3 43 3 45 35  535 4  43 3 32  4434 4 2347 23  32 3233 2";
    int num = 0;
    int num_arr_order = 0;
    for (int i = 0; i < LEN; ++i) {
        num *= 10;
        num += char_to_int(process_string[i]);
        if (process_string[i] == ' ') {
            if (num != 0) {
                printf("num: %d\n", num / 10);
                num_arr[num_arr_order] = num / 10;
                num_arr_order++;
            }
            num = 0;
        }
        if (process_string[i] == '\0')break;
    }
    printf("num: %d\n", num / 10);
    num_arr[num_arr_order] = num / 10;

    printf("\n\n");

    int array_length = 0;
    for (int i = 0; i < LEN / 2; ++i) {
        if (num_arr[i] == 0)break;
        array_length++;
    }
    printf("\n\t%d\n\n", array_length);
    int *num_array = (int *) malloc(array_length * sizeof(int));
    for (int i = 0; i < array_length; ++i) {
        num_array[i] = num_arr[i];
        printf("\n%d", num_array[i]);
    }

    printf("\n\n");
    printf("%1.0f", pow(2,array_length));



}


int char_to_int(char C) {
    int tmp = C - 48;
    if (tmp < 0 || tmp >= 10) {
        return 0;
    }
    return C - 48;
}