#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
   string word1 = get_string("Player 1: ");
   string word2 = get_string("Player 2: ");

   int score1 = compute_score(player1);
   int socre2 = compute_score(player2);


}
int compute_score(string word)
{
    int score = 0
    len = strlen(word);
    for(i = 0, i < len, i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i]] - 'A'
        }
    }
}
