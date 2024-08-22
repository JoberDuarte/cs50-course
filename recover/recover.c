#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 if  (argv != 2 )
 {
    printf("Usage: ./recover FILE\n");
    return 1;
 }

 FILE *card = fopen(argv[1], "r");
 if (card == NULL)
 {
    printf("Could not open this card\n");
    return 1;
 }
}
