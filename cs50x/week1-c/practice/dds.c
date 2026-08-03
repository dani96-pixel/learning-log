/**
 * ============================================================================
 * Problem to Solve: The Dividend & Debt Compounding Simulator (DDS)
 * ============================================================================
 *
 * In the world of finance, two forces often race against each other: the
 * growth of investments through compound interest and the reduction of debt
 * through consistent payments [1, 2]. While an investment portfolio
 * typically grows exponentially, a debt balance decreases linearly or
 * exponentially depending on the interest rate and payment schedule.
 * Understanding the "Break-even Year"—the exact moment your assets exceed
 * your liabilities—is a fundamental skill in financial engineering.
 *
 * However, computers have limitations when handling these calculations.
 * Using a standard 32-bit 'int' to store large sums of money can lead to
 * "Integer Overflow," where the value becomes so large it wraps around to
 * a negative number [3, 4]. Similarly, representating decimal values
 * using 'float' can introduce "Floating Point Imprecision," leading to
 * subtle mathematical errors [5, 6].
 *
 * In a file called dds.c in a folder called practice, implement a program
 * in C that simulates this financial race, identifying when an investment
 * portfolio officially covers a remaining debt.
 *
 * ============================================================================
 * The Core Logic: Compounding and Amortization
 * ============================================================================
 *
 * To determine the financial status year over year, the program must:
 *
 * 1. Annual Growth: Multiply the current investment balance by the
 *    annual interest rate (e.g., balance = balance * (1 + rate)). In C,
 *    this requires a loop if you avoid external math libraries,
 *    incrementing the value year by year [7-9].
 *
 * 2. Debt Reduction: Subtract the total annual payments from the debt
 *    balance. A common challenge is ensuring the debt does not
 *    accidentally "overflow" or drop below zero without stopping
 *    the simulation [3].
 *
 * 3. Comparison: Use a "Boolean Expression" to check every year if
 *    investment >= debt. If true, the "Break-even" point is reached [10, 11].
 *
 * ============================================================================
 * Implementation Details
 * ============================================================================
 *
 * Write a program that prompts the user for four values: Initial Investment,
 * Annual Interest Rate, Initial Debt, and Annual Payment.
 *
 * To ensure professional quality and correctness:
 *
 * - Input Validation: Use 'do-while' loops to ensure the user provides
 *   positive numbers [12, 13]. If the input is negative, the program
 *   should re-prompt the user indefinitely until they cooperate [14, 15].
 *
 * - Data Types: Do not assume these values will fit in an 'int'! Use
 *   'double' for high-precision decimal calculations or 'long long'
 *   for large monetary sums to prevent overflow [5, 16, 17].
 *
 * - Abstraction: Your 'main' function must be at the top of the file [18].
 *   You must use "Function Prototypes" above 'main' to declare your custom
 *   financial functions [19].
 *
 * - Output Formatting: Use 'printf' with placeholders like '%.2f' to
 *   ensure the money is displayed with exactly two decimal places,
 *   maintaining a clean ASCII table structure [20-22].
 *
 * Consider the below representative of how your program should behave:
 *
 * $ ./dds
 * Initial Investment: 5000
 * Annual Rate (e.g. 0.05): 0.07
 * Initial Debt: 10000
 * Annual Payment: 2000
 *
 * Year | Investment   | Debt         | Difference
 * --------------------------------------------------
 * 0    | 5000.00      | 10000.00     | -5000.00
 * 1    | 5350.00      | 8000.00      | -2650.00
 * 2    | 5724.50      | 6000.00      | -275.50
 * 3    | 6125.22      | 4000.00      | 2125.22
 * --------------------------------------------------
 * Break-even achieved in Year 3!
 *
 * ============================================================================
 */

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

// Prototypes
double calculate_growth(double balance, double rate);
double apply_payment(double debt, double payment);
bool check_status(double investment, double debt);
void print_report_row(int year, double inv, double debt, double diff);

int main(void)
{
    // Robust Input validation
    // Define the vars
    double initial_investment;
    double annual_rate;
    double debt;
    double annual_debt_payment;
    double difference;
    int year;
    bool status;

    // Ask for I. Investment, Annual rate, Debt and Annual Debt Payment
    do
    {
        initial_investment = get_double("Initial Investment: ");
    } while (initial_investment < 0);

    do
    {
        annual_rate = get_double("Annual Rate (e.g. 0.05): ");
    } while (annual_rate < 0);

    do
    {
        debt = get_double("Initial Debt: ");
    } while (debt < 0);

    do
    {
        annual_debt_payment = get_double("Annual Payment: ");
    } while (annual_debt_payment < 0);

    printf("\n");
    // Iniatialize the needed variables
    difference = initial_investment - debt;
    year = 0;

    // Print the beggining of the table
    // Header
    printf("%-5s | %-14s | %-14s | %-14s\n",
           "Year", "Investment", "Debt", "Difference");
    printf("--------------------------------------------------\n");

    // Body | Year 0
    print_report_row(year, initial_investment, debt, difference);
    double investment = initial_investment;

    status = check_status(initial_investment, debt);

    // Main Loop for compute the values
    while (!status)
    {
        if (year >= 100)
        {
            printf("--------------------------------------------------\n");
            printf("Iterations Limit reached (100 tries)!!\n");
            break;
        }
        investment = calculate_growth(investment, annual_rate);
        debt = apply_payment(debt, annual_debt_payment);
        difference = (investment - debt);
        year += 1;
        status = check_status(investment, debt);
        print_report_row(year, investment, debt, difference);
    }

    if (status == true)
    {
        printf("--------------------------------------------------\n");
        printf("Break-even achieved in Year %i!\n", year);
    }
}

// Functions Implementation

// 1. Func Calculate Growth (Receives balance and rate)
double calculate_growth(double balance, double rate)
{
    double calculated_growth = balance + (balance * rate);
    return calculated_growth;
}

// 2. Func Apply Payment (Receives debt and payment)
double apply_payment(double debt, double payment)
{
    if (payment >= debt)
    {
        debt = 0;
    }

    else
    {
        debt -= payment;
    }

    return debt;
}

// 3. Func Check Status (Receives investment and debt)
bool check_status(double investment, double debt)
{
    if (investment >= debt)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// 4. Func Print Report (receives year, inv and debt)
void print_report_row(int year, double inv, double debt, double diff)
{
    printf("%-5d | %-14.2f | %-14.2f | %-14.2f\n", year, inv, debt, diff);
}