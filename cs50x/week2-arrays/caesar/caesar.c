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
they’ll provide at runtime. It is assumed that the user will enter a positive integer value for the key.
*/

int main(int argc, string argv[])
{
    // Check if there are exactly 1 command line arguments provided
    if (argc != 2)
    {
        printf("Error: too few or too many arguments provided.\n");
        printf("Usage: ./caesar <key>\n");
        return 1;
    }

    // Validate that the first argument is a valid integer key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Error: invalid input. Please enter an integer value.\n");
            return 1;
        }
    }

    // Convert the first argument to a positive integer key
    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("Error: key must be a non-negative integer.\n");
        return 1;
    }

    // Normalize the key value within the range of 0-25
    k %= 26;

    // Prompt the user for the plaintext message to encrypt
    printf("plaintext: ");
    string plaintext = get_string("");

    printf("ciphertext: ");
    // For each character in the plaintext, Rotate the character if it's a letter
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char letter = plaintext[i];
        if (!isalpha(letter))
        {
            printf("%c", letter);
        }
        else
        {
            // Apply Caesar's cipher to the letter, handling both uppercase and lowercase letters
            int position = (letter - isupper(letter) ? 'a' : 'A') + k;
            position %= 26;

            if (isupper(letter))
            {
                printf("%c", position + 'A');
            }
            else
            {
                printf("%c", position + 'a');
            }
        }
    }
    printf("\n");
    return 0;
}