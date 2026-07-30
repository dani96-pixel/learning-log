#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for a height of the pyramid
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n < 1 || n > 8);

    // =============Print the pyramid=============

    // For loop to iterate rows and print the jumpspace at the end
    for (int i = 0; i < n; i++)
    {
        // For loop to print the spaces for the row
        for (int j = 0; j < n - (i + 1); j++)
        {
            printf(" ");
        }

        // For loop to print the hashes for the row
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Print the space between pyramids
        printf("  ");

        // Loop to print the next pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Jumpspace
        printf("\n");
    }
}