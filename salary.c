#include <stdio.h>

/*
 * Portfolio submission
 * Name: Ahmad Hammouri
 * ID: 201952967
 */

int main( void ) {

    // define and initialise variables for the problem data
    double salary = 36250.0;
    double ni_rate = 8.0;     // %
    double tax_rate = 15.0;   // %
    double tax_free_allowance = 12500.0;

    // calculate the deductions and final take-home salary
    double ni_contribution = salary * (ni_rate / 100.0);

    double remaining_after_ni = salary - ni_contribution;

    double taxable_amount = remaining_after_ni - tax_free_allowance;
    if (taxable_amount < 0.0) {
        taxable_amount = 0.0;
    }

    double tax_contribution = taxable_amount * (tax_rate / 100.0);

    double take_home_salary = salary - ni_contribution - tax_contribution;

    // Use only these print statement with appropriate formatting and variable names
    printf("Salary £%.2f\n", salary);
    printf("NI contribution £%.2f\n", ni_contribution);
    printf("Tax contribution £%.2f\n", tax_contribution);
    printf("Take home salary £%.2f\n", take_home_salary);

    return 0;
}