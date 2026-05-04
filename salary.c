#include <stdio.h>

/*
 * Portfolio submission
 * Name:
 * ID:
 */

int main(void) {

    // define and initialise variables for the problem data
    float salary = 36250.0f;
    float niRate = 8.0f;
    float taxRate = 15.0f;
    float taxFreeAllowance = 12500.0f;

    // calculate the deductions and final take-home salary
    float niContribution = salary * niRate / 100.0f;
    float taxableSalary = salary - niContribution - taxFreeAllowance;

    if (taxableSalary < 0.0f) {
        taxableSalary = 0.0f;
    }

    float taxContribution = taxableSalary * taxRate / 100.0f;
    float takeHomeSalary = salary - niContribution - taxContribution;

    // Use only these print statement with appropriate formatting and variable names
    printf("NI contribution £%.2f\n", niContribution);
    printf("Tax contribution £%.2f\n", taxContribution);
    printf("Take home salary £%.2f\n", takeHomeSalary);

    return 0;
}