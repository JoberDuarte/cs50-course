#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    int len = strlen(argv[1]);


    if(argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else if(len != 26)
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

    int len_plaintext = strlen(plaintext);

    for(int i = 0; i < len_plaintext; i++)
    {
        if(isupper(plaintext[i]))
        
    }


}
