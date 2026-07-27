#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for a height of the pyramid
    int n;
    do
    {
        n = get_int("Pyramid height: ");
    } while (n < 1);

    // Print the pyramid
}