#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("TEXT: ");

    int letter = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    

    printf("Letters : %i\n", letter);
    printf("Words : %i\n", words);
    printf("Sentences : %i\n", sentences);


}

int count_letters(string text)
{
   int letter = 0;
   int len = strlen(text);

   for(int i = 0; i < len; i++)
   {
    if(isalpha(text[i]))
    {
        letter++;
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
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int len = strlen(text);

    for(int i = 0; i < len; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++ ;
        }
    }
    return sentences;
}
