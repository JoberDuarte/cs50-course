# include<cs50.h>
# include <stdio.h>

int main(void)
{
    string name = get_string("What is your name? ");
    int age = get_int("What is your age? ");
    string fone = get_string("what is your fone number? ");

    printf(" Hello %s, Your age is %i and your fone number is %s\n", name, age, fone);
}
