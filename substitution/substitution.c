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
}

