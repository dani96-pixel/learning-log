#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

// In a file called readability.c in a folder called readability,
// you’ll implement a program that calculates the approximate
// grade level needed to comprehend some text. Your program
// should print as output “Grade X” where “X” is the grade level
// computed, rounded to the nearest integer. If the grade level
// is 16 or higher (equivalent to or greater than a senior
// undergraduate reading level), your program should output
// “Grade 16+” instead of giving the exact index number. If the
// grade level is less than 1, your program should output
// “Before Grade 1”.

// Promises
int count_words(string s);
double compute_letters(string s);
double compute_sentences(string s);
double compute_coleman_liau_index(double L, double S);

// Main Logic
int main(void)
{
    string text = get_string("Text: ");

    double letters = compute_letters(text);
    double sentences = compute_sentences(text);
    int grade = compute_coleman_liau_index(letters, sentences);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    return 0;
}

// Custom Functions
int count_words(string s)
{
    int i = 0;
    int words = 1;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            words += 1;
        }
        i += 1;
    }
    return words;
}

double compute_letters(string s)
{
    int i = 0;
    int number_of_letters = 0;
    while (s[i] != '\0')
    {
        s[i] = tolower(s[i]);
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            number_of_letters += 1;
        }
        i += 1;
    }

    int number_of_words = count_words(s);
    double letters = (float)number_of_letters / (float)number_of_words * 100;
    return letters;
}

double compute_sentences(string s)
{
    int i = 0;
    int number_of_sentences = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            number_of_sentences += 1;
        }
        i += 1;
    }

    int number_of_words = count_words(s);
    double sentences = (float)number_of_sentences / (float)number_of_words * 100;
    return sentences;
}

double compute_coleman_liau_index(double L, double S)
{
    double index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    return index;
}