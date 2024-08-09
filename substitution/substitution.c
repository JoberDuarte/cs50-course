#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validation(string key);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    if(validation(argv[1]) != 0)
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    



    int len_plaintext = strlen(plaintext);
    int result = 0;
    for(int i = 0; i < len_plaintext; i++)
    {
        if(isupper(plaintext[i]))
        {
            result = (plaintext[i] - 'A');
            printf("%c", toupper(argv[1][result]));
        }
        else if(islower(plaintext[i]))
        {
            result = (plaintext[i] - 'a');
            printf("%c", tolower(argv[1][result]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n")



}

int validation(string key)
{
    int len = strlen(key);

    if (len != 26)
    {
        printf("KEY must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("KEY must contain only alphabetic characters\n");
        return 1;

        }
    }
    for (int i = 0; i < len; i++)
    {

        for(int j = i+1; j < len ; j++)
        {
            if(key[i] == key[j])
            {
                printf("KEY must not contain repeated characters\n");
                return 1;
            }
        }
    }
    return 0;
}
