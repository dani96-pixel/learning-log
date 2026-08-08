#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// scrabble.c
// In a file called scrabble.c in a folder called scrabble,
// implement a program in C that determines the winner of
// a short Scrabble-like game. Your program should prompt
// for input twice: once for “Player 1” to input their word
// and once for “Player 2” to input their word. Then,
// depending on which player scores the most points, your
// program should either print “Player 1 wins!”, “Player 2
// wins!”, or “Tie!” (in the event the two players score
// equal points).

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_word(string s);

void print_winner_case(int player_00_score, int player_01_score);

int main(void)
{
    string word_00 = get_string("Player 1: ");
    string word_01 = get_string("Player 2: ");

    // Create vars to work
    int len_00 = strlen(word_00);
    int len_01 = strlen(word_01);

    char my_word_00[len_00 + 1];
    char my_word_01[len_01 + 1];

    strcpy(my_word_00, word_00);
    strcpy(my_word_01, word_01);

    // Compute the points and show results
    int word_00_points = compute_word(my_word_00);
    int word_01_points = compute_word(my_word_01);

    print_winner_case(word_00_points, word_01_points);
    return 0;
}

int compute_word(string s)
{
    int score = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = tolower(s[i]);
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            int point_index = s[i] - 'a';
            score += POINTS[point_index];
        }
        i += 1;
    }
    return score;
}

void print_winner_case(int player_00_score, int player_01_score)
{
    if (player_00_score > player_01_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_00_score < player_01_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}