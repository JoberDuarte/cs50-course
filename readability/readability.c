#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("TEXT: ");

    int letter = count_letters(text);
    int words = count_words(text);

    printf("Letters : %i\n", letter);
    printf("Words : %i\n", words);


}

int count_letters(string text)
{
   int letter = 0;
   int len = strlen(text);

   for(int i = 0; i < len; i++)
   {
    if(isalpha(text[i]))
    {
        letter += 1;
    }
   }
   return letter;
}

int count_words(string text)
{
    int words = 1;
    int len  = strlen(text);

    for(int i = 0; i < len; i++)
    {
        if(isspace(text[i]))
        {
            words += 1;
        }
    }
    return words;
}
