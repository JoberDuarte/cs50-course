#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Charge owed: ");
    }
    while (cash < 0);

    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}
