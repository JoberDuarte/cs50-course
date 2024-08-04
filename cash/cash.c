#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cash;
    do
    {
        cash = get_int("Charge owed: ");
    }
    while (cash < 0);

}
