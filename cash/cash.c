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

    int dimes = 0
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 15;
    }
    return dimes;

    int nickels;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;

    int pennies;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;

    sum = quarters + dimes + 

}
