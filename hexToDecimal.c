#include <stdio.h>

int main(void) {
    char hex[9];
    unsigned int decimal = 0;

    scanf("%8s", hex);

    for (int i = 0; hex[i] != '\0'; i++) {
        int value;

        if (hex[i] >= '0' && hex[i] <= '9') {
            value = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            value = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            value = hex[i] - 'a' + 10;
        } else {
            printf("Error: Invalid Hexadecimal\n");
            return 0;
        }

        decimal = decimal * 16 + value;
    }

    printf("%u\n", decimal);

    return 0;
}