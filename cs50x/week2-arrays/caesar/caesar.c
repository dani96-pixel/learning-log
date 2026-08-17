// caesar.c
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/*
In a file called caesar.c in a folder called caesar, write a program
that enables you to encrypt messages using Caesar’s cipher. At the
time the user executes the program, they should decide, by providing
a command-line argument, what the key should be in the secret message
they’ll provide at runtime. We shouldn’t necessarily assume that the
user’s key is going to be a number; though you may assume that, if it
is a number, it will be a positive integer.
*/

int main(int argc, string argv[])
{
    // Check if there are exactly 1 command line arguments provided
    if (argc != 2)
    {
        // Explain why it will not work and give the solution
        printf("Error: caesar.c admits exactly 1 command line argument\n");
        printf("Usage: ./caesar key");
        return 1;
    }

    // Validate that the first argument is a valid integer key
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the first argument to a positive integer key
    int k = atoi(argv[1]);

    // Normalize the key value within the range of 0-25
    if (k < 0)
    {
        printf("The Key must be a positive integer\n");
        return 1;
    }

    // Make it sure is between 1 and 26
    k %= 26;

    // Prompt the user for the plaintext message to encrypt
    printf("plaintext: ");
    string plaintext = get_string(" ");

    printf("ciphertext: ");
    // For each character in the plaintext, Rotate the character if it's a letter
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else
        {
            char letter = plaintext[i];
            if (isupper(letter))
            {
                int pi = letter - 'A';
                int ci = (pi + k) % 26;
                char new_letter = ci + 'A';
                printf("%c", new_letter);
            }
            else
            {
                int pi = letter - 'a';
                int ci = (pi + k) % 26;
                char new_letter = ci + 'a';
                printf("%c", new_letter);
            }
        }
    }
    printf("\n");
    return 0;
}