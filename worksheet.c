#include <stdio.h>
#include <math.h>

/*
 * Portfolio submission
 * Name: Ahmad Hammouri
 * ID: 201952967
 */

int add_values(int a, int b) {
    return a + b;
}

void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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
        int temp = array[i];
        array[i] = array[length - 1 - i];
        array[length - 1 - i] = temp;
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

/* Simple test runner */

int test_add_values(void) {
    return add_values(3, 4) == 7 &&
           add_values(-2, 5) == 3 &&
           add_values(0, 0) == 0;
}

int test_swap_values(void) {
    int a = 3;
    int b = 4;

    swap_values(&a, &b);

    return a == 4 && b == 3;
}

int test_sum_array(void) {
    int values[] = {1, 2, 3, 4, 5};

    return sum_array(values, 5) == 15;
}

int test_reverse_array(void) {
    int values[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};

    reverse_array(values, 5);

    for (int i = 0; i < 5; i++) {
        if (values[i] != expected[i]) {
            return 0;
        }
    }

    return 1;
}

int test_average(void) {
    int values[] = {1, 2, 3, 4, 5};
    double result = average(values, 5);

    return fabs(result - 3.0) < 0.0001;
}

int test_find_max(void) {
    int values[] = {3, 9, 2, 7, 5};
    int max_value = 0;

    find_max(values, 5, &max_value);

    return max_value == 9;
}

void print_result(const char *test_name, int passed) {
    if (passed) {
        printf("Test %s...       [ OK ]\n", test_name);
    } else {
        printf("Test %s...       [ FAILED ]\n", test_name);
    }
}

int main(void) {
    print_result("add_values", test_add_values());
    print_result("swap_values", test_swap_values());
    print_result("sum_array", test_sum_array());
    print_result("reverse_array", test_reverse_array());
    print_result("average", test_average());
    print_result("find_max", test_find_max());

    return 0;
}