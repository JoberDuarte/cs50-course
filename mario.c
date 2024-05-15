#include <cs50.h>
#include <stdio.h>

void print_row(int length);
int main(void)
{
    int height = get_int("Height: ");
    print_row(height);
}

void print_row(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }
    printf("\n");
}
