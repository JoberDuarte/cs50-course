#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("TEXT: ");

    int letter = count_letters(text);

    printf("%i\n", letter);


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
}
