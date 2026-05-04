#include <stdio.h>

/*
 * Task 1 Functions Practice
 * Name:
 * ID:
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

    return (double) sum_array(array, length) / length;
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

int main(void) {
    int a = 3;
    int b = 4;

    printf("add_values(3, 4) = %d\n", add_values(a, b));

    swap_values(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    int numbers[] = {1, 2, 3, 4, 5};
    int length = 5;

    printf("sum_array = %d\n", sum_array(numbers, length));
    printf("average = %.2f\n", average(numbers, length));

    int max_value;
    find_max(numbers, length, &max_value);
    printf("max = %d\n", max_value);

    reverse_array(numbers, length);

    printf("reversed array:");
    for (int i = 0; i < length; i++) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    return 0;
}