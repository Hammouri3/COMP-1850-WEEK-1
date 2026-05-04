#include <stdio.h>

/*
 * Task 1 Functions Practice
 */

int add_values(int a, int b) {
    return a + b;
}

void swap_values(int *a, int *b) {
    int temporary = *a;
    *a = *b;
    *b = temporary;
}

int sum_array(int *array, int length) {
    int total = 0;

    for (int i = 0; i < length; i++) {
        total += array[i];
    }

    return total;
}

void reverse_array(int *array, int length) {
    for (int i = 0; i < length / 2; i++) {
        int temporary = array[i];
        array[i] = array[length - 1 - i];
        array[length - 1 - i] = temporary;
    }
}

double average(int *array, int length) {
    if (length == 0) {
        return 0.0;
    }

    int total = sum_array(array, length);
    return (double) total / length;
}

void find_max(int *array, int length, int *max_value) {
    if (length <= 0) {
        return;
    }

    *max_value = array[0];

    for (int i = 1; i < length; i++) {
        if (array[i] > *max_value) {
            *max_value = array[i];
        }
    }
}