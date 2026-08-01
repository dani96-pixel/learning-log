#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

// =========================================================================
// FUNCTION PROTOTYPES (Your promises to the compiler)
// =========================================================================

// Prototype: Function 1 (Count digits). Receives a long long, returns an int.
// Prototype: Function 2 (Extract prefix). Receives a long long, returns an int (the first 2 digits).
// Prototype: Function 3 (Luhn's algorithm). Receives a long long, returns a bool.
// Prototype: Function 4 (Split and sum product). Receives an int, returns an int.

// =========================================================================
// MAIN FUNCTION
// =========================================================================

// Start main function
// {
// 1. Prompt the user for a credit card number and store it in a long long.

// 2. Call Function 1 passing the card number and store the digit count in a variable.

// 3. Validate length boundaries:
//    If the digit count is NOT 13, AND NOT 15, AND NOT 16:
//        Print "INVALID\n"
//        Terminate the program by returning 0

// 4. Call Function 2 passing the card number and store the prefix (first 2 digits) in a variable.

// 5. Call Function 3 (Luhn) passing the card number and store the boolean result.

// 6. Verify mathematical validity and company:
//    If Luhn is false:
//        Print "INVALID\n"
//    If Luhn is true, classify the card:
//        - If it has 15 digits AND the prefix is 34 or 37: Print "AMEX\n"
//        - If it has 16 digits AND the prefix is between 51 and 55: Print "MASTERCARD\n"
//        - If it has 13 or 16 digits AND the first digit is 4 (hint: if prefix divided by 10 equals 4): Print "VISA\n"
//        - If it passes Luhn but doesn't meet any of the prefix rules above: Print "INVALID\n"
// }

// =========================================================================
// FUNCTION IMPLEMENTATIONS
// =========================================================================

// --- Function 1: Count digits ---
// Declare function (receives long long, returns int)
// {
// Initialize a counter to 0.
// Start a while loop (while the number is greater than 0).
// Inside the loop:
// Divide the number by 10.
// Increase the counter by 1.
// Return the counter.
// }

// --- Function 2: Extract prefix (first two digits) ---
// Declare function (receives long long, returns int)
// {
// Start a while loop (while the number is greater than or equal to 100).
// Inside the loop:
// Divide the number by 10.
// (This will stop the loop exactly when only 2 digits remain).
// Return the remaining number.
// }

// --- Function 3: Luhn's Algorithm ---
// Declare function (receives long long, returns bool)
// {
// Declare a variable for the total sum initialized to 0.
// Declare a variable to keep track of the position initialized to 1.

// Start a while loop (while the card number is greater than 0).
// Inside the loop:
// Extract the last digit using modulo 10.

// If the position is odd (e.g., 1, 3, 5...):
// Add that digit directly to the total sum.

// If the position is even (e.g., 2, 4, 6...):
// Multiply the digit by 2.
// Call Function 4 passing this product.
// Add the value returned by Function 4 to the total sum.

// Divide the card number by 10 to remove the digit we just processed.
// Increase the position counter by 1.

// After exiting the loop, check if the last digit of the total sum is 0 (total sum % 10 == 0).
// If it is 0, return true. If not, return false.
// }

// --- Function 4: Split product and sum ---
// Declare function (receives int, returns int)
// {
// If the received product is greater than 9:
// Return (product / 10) + (product % 10)
// Else:
// Return the product just as it came in.
// }

/*
{
    // Define the result var
    string result;

    // Ask for a long
    long long user_card = get_long_long("Number: ");

    // Verify a long
    // Do the checksum
    // Do the card company
    // Get the result
    // Print result of the long

    // Test
    // Create a var I can destroy without problems
    long long var_to_work = user_card;
    int counter = 0;
    while (var_to_work >= 1)
    {
        var_to_work /= 10;
        counter += 1;
        printf("Number: %lli\nCounter: %i\n\n", var_to_work, counter);
    }

    printf("LLI after the process: %lli\n", user_card);
}
*/