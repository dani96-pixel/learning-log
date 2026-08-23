// substitution.c
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Checks if a provided key is valid for substitution.
 *
 * A valid key must be exactly 26 characters long, contain only letters,
 * and ensure that every letter is unique (case-insensitive).
 *
 * @param input The string to validate as a key.
 * @return bool True if the key is valid, false otherwise.
 */
bool verify_key(string input);

/**
 * Applies a substitution cipher to a plaintext string.
 *
 * It replaces every alphabetic character in the input with the
 * corresponding character from the key, preserving case and
 * non-alphabetic characters.
 *
 * @param input The plaintext string to be substituted.
 * @param key The 26-letter substitution key.
 * @param output A buffer where the resulting ciphertext will be stored.
 */
void apply_substitution(string input, string key, string output);

/**
 * Main function to run the substitution cipher.
 *
 * Expects one command-line argument: the substitution key.
 * Prompts the user for plaintext and outputs the resulting ciphertext.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int Returns 0 on success, or 1 if usage error or key error occurs.
 */
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    bool is_key = verify_key(argv[1]);
    if (!is_key)
    {
        printf("Error: key must contain 26 different alphabetic characters");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext:  ");

    int lenght = strlen(plaintext);
    char ciphertext[lenght + 1];

    apply_substitution(plaintext, key, ciphertext);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool verify_key(string input)
{
    int lenght = strlen(input);
    if (lenght != 26)
    {
        return false;
    }

    for (int i = 0; i < lenght; i++)
    {
        if (!isalpha(input[i]))
        {
            return false;
        }
    }

    for (int i = 0; i < lenght; i++)
    {
        for (int j = i + 1; j < lenght; j++)
        {
            if (tolower(input[i]) == tolower(input[j]))
            {
                return false;
            }
        }
    }

    return true;
}

void apply_substitution(string input, string key, string output)
{
    int i = 0;
    while (input[i] != '\0')
    {
        char element = input[i];

        if (isalpha(element))
        {
            int alphabet_position;
            if (isupper(element))
            {
                alphabet_position = element - 'A';
            }
            else
            {
                alphabet_position = element - 'a';
            }

            char new_letter = key[alphabet_position];

            if (isupper(element))
            {
                output[i] = toupper(new_letter);
            }
            else
            {
                output[i] = tolower(new_letter);
            }
        }
        else
        {
            output[i] = element;
        }

        i++;
    }

    output[i] = '\0';
}