//
// Created by tomokazu on 2022/04/08.
//

#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LEN 5000
#define MATCH_NUM 237

int char_to_int(char C);

int main(void) {

    char *process_string = calloc(LEN, sizeof(char));
    int *num_arr = malloc(sizeof(int) * LEN / 2);
    memset(num_arr, 0, sizeof(int) * LEN / 2);
    process_string = "34 35 22 5 23 65 54 76 92 46 26 32 17 16 151 5 18";
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
    printf("変数 %d\n", (int) pow(2, array_length));
    int *match_num = malloc(LEN * sizeof(int));

    int k, num_sum, bin_num, matches;
    matches = 0;
    for (int i = 0; i < (int) pow(2, array_length); ++i) {
        k = i;
        num_sum = 0;
        //printf("%d\n", (int) k);
        //printf("\n");
        for (int j = 0; j < array_length; ++j) {
            bin_num = (int) (k / pow(2, array_length - j - 1));
            //printf("%d ", bin_num);
            if (bin_num == 1) {
                //printf("-");
            } else {
                //printf("+");
            }
            //printf("%d", num_array[j]);

            num_sum += num_array[j] * (int) pow(-1, bin_num);
            k -= bin_num * (int) pow(2, array_length - j - 1);
        }
        //printf("\n");
        //printf("num_sum: %d\n", num_sum);
        if (MATCH_NUM == num_sum) {
            match_num[matches] = i;
            matches++;
        }
    }

    printf("\nMatches:\n");
    for (int i = 0; i < matches; i++) {
        printf("%dつ目\t", i + 1);
        printf("%d番目\n\t", match_num[i]);
        k = match_num[i];
        for (int j = 0; j < array_length; ++j) {
            bin_num = (int) (k / pow(2, array_length - j - 1));
            //printf("%d ", bin_num);
            if (bin_num == 1) {
                printf("-");
            } else {
                printf("+");
            }
            printf("%d", num_array[j]);

            num_sum += num_array[j] * (int) pow(-1, bin_num);
            k -= bin_num * (int) pow(2, array_length - j - 1);
        }
        printf("=%d\n", MATCH_NUM);

    }


}


int char_to_int(char C) {
    int tmp = C - 48;
    if (tmp < 0 || tmp >= 10) {
        return 0;
    }
    return C - 48;
}