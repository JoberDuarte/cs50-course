#include <cs50.h>
#include <stdio.h>


int calculate_quarters(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Charge owed: ");
    }
    while (cents < 0);

    int quarters = calculate_quarters(cents);
    cents = cents - (quarters *25);
    printf()



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

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 15;
    }
    return dimes;
}
int calculate_nickles(int cents)
{
    int nickels;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}
int calculate_pennies(int cents)
{
    int pennies;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}

    int sum = quarters + dimes + nickels + pennies;

    printf("%i", sum);


