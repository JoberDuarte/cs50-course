#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    int len = strlen(argv[1]);

    if (len != 26)
    {
        printf("KEY must contain 26 characters\n");
        return 1;
    }

    printf("%i\n", len);

    for (int i = 0; i < len; i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("KEY must contain only alphabetic characters\n");
        return 1;

        }
    }
    for (int i = 0; i < len; i++)
    {

        for(int j = i+1; j < len ; j++)
        {
            if(argv[1][i] == argv[1][j])
            {
                printf("KEY must not contain repeated characters\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");

    printf("Testando ate aqui\n");

    int len_plaintext = strlen(plaintext);
    int result = 0;
    for(int i = 0; i < len_plaintext; i++)
    {
        if(isupper(plaintext[i]))
        {
            result = (plaintext[i] - 'A');
            printf("%c", argv[1][result]);
        }
        else if(islower(plaintext[i]))
        {
            result = (plaintext[i] - 'a');
            printf("%c", argv[1][result]);
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");


}

bool validation(key)
int len = strlen(key);

    if (len != 26)
    {
        printf("KEY must contain 26 characters\n");
        return 1;
    }

    printf("%i\n", len);

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
