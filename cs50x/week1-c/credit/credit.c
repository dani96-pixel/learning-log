#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

// =========================================================================
// FUNCTION PROTOTYPES
// =========================================================================

// Prototype: Function 1 (Count digits). Receives a long long, returns an int.
int count_digits(long long number);

// Prototype: Function 2 (Extract prefix). Receives a long long, returns an int (the first 2 digits).
int extract_prefix(long long card);

// Prototype: Function 3 (Luhn's algorithm). Receives a long long, returns a bool.
bool luhn(long long card);

// Prototype: Function 4 (Split and sum product). Receives an int, returns an int.
int split_and_sum_product(int product);

// =========================================================================
// MAIN FUNCTION
// =========================================================================

// Start main function
int main(void)
{
    // {
    // 1. Prompt the user for a credit card number and store it in a long long.
    long long user_card = get_long_long("Number: ");

    // 2. Call Function 1 passing the card number and store the digit count in a variable.
    int card_digits = count_digits(user_card);

    // 3. Validate length boundaries:
    //    If the digit count is not 13 or 15 or 16:
    if (card_digits != 13 && card_digits != 15 && card_digits != 16)
    {
        //        Print "INVALID"
        printf("INVALID\n");
        //        Terminate the program by returning 0
        return 0;
    }

    // 4. Call Function 2 passing the card number and store the prefix (first 2 digits) in a variable.
    int prefix = extract_prefix(user_card);

    // 5. Call Function 3 (Luhn) passing the card number and store the boolean result.
    bool luhn_result = luhn(user_card);

    // 6. Verify mathematical validity and company:
    //    If Luhn is false:
    if (luhn_result == false)
    {
        //        Print "INVALID\n"
        printf("INVALID\n");
    }
    else
    {
        //    If Luhn is true, classify the card:
        //        - If it has 15 digits AND the prefix is 34 or 37: Print "AMEX\n"
        if (card_digits == 15 && (prefix == 34 || prefix == 37))
        {
            printf("AMEX\n");
        }
        //        - If it has 16 digits AND the prefix is between 51 and 55: Print "MASTERCARD\n"
        else if (card_digits == 16 && (prefix >= 51 && prefix <= 55))
        {
            printf("MASTERCARD\n");
        }
        //        - If it has 13 or 16 digits AND the first digit is 4: Print "VISA\n"

        else if ((card_digits == 13 || card_digits == 16) && ((prefix / 10) == 4))
        {
            printf("VISA\n");
        }
        //        - If it passes Luhn but doesn't meet any of the prefix rules above: Print "INVALID\n"
        else
        {
            printf("INVALID\n");
        }
        // }
    }
}

// =========================================================================
// FUNCTION IMPLEMENTATIONS
// =========================================================================

// --- Function 1: Count digits ---
// Declare function (receives long long, returns int)
int count_digits(long long number)
{
    // {
    // Initialize a counter to 0.
    int counter = 0;

    // Start a while loop (while the number is greater than 0).
    while (number > 0)
    {
        // Divide the number by 10.
        number /= 10;

        // Increase the counter by 1.
        counter += 1;
    }

    // Return the counter.
    return counter;
    // }
}

// --- Function 2: Extract prefix (first two digits) ---
// Declare function (receives long long, returns int)
int extract_prefix(long long card)
{
    // {
    // Start a while loop (while the number is greater than or equal to 100).
    while (card >= 100)
    {
        // Divide the number by 10.
        card /= 10;
    }

    // Return the remaining number.
    return card;
    // }
}

// --- Function 3: Luhn's Algorithm ---
// Declare function (receives long long, returns bool)
bool luhn(long long card)
{
    // {
    // Declare a variable for the total sum initialized to 0.
    int total_sum = 0;

    // Declare a variable to keep track of the position initialized to 1.
    int position = 1;

    // Start a while loop (while the card number is greater than 0).
    while (card > 0)
    {
        // Extract the last digit using modulo 10.
        int last_digit = card % 10;

        // If the position is odd (e.g., 1, 3, 5...):
        if (position % 2 != 0)
        {
            // Add that digit directly to the total sum.
            total_sum += last_digit;
        }

        // If the position is even (e.g., 2, 4, 6...):
        else
        {
            // Multiply the digit by 2.
            last_digit *= 2;

            // Call Function 4 passing this product.
            last_digit = split_and_sum_product(last_digit);

            // Add the value returned by Function 4 to the total sum.
            total_sum += last_digit;
        }

        // Divide the card number by 10 to remove the digit we just processed.
        card /= 10;

        // Increase the position counter by 1.
        position += 1;
    }

    // After exiting the loop, check if the last digit of the total sum is 0 (total sum % 10 == 0).
    if (total_sum % 10 == 0)
    {
        // If it is 0, return true. If not, return false.
        return true;
    }
    else
    {
        return false;
    }
    // }
}

// --- Function 4: Split product and sum ---
// Declare function (receives int, returns int)
int split_and_sum_product(int product)
{
    // {
    // If the received product is greater than 9:
    if (product > 9)
    {
        // Return (product / 10) + (product % 10)
        int result = (product / 10) + (product % 10);
        return result;
    }

    // Else:
    else
    {
        // Return the product just as it came in.
        return product;
    }
    // }
}