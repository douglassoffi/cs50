#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main (void)
{
    float dollars;
    do
    {
        dollars = get_float("Dollars owed: ");
    }
    while (dollars <= 0);

    int cents = round(dollars * 100);

    printf("Cents owed: %i\n", cents);

    int coins = 0;

    while (cents != 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
            coins++;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
            coins++;
        }
        else
        {
            cents--;
            coins++;
        }
        printf("Cents: %i - Coins: %i\n", cents, coins);
    }
    printf("Coins: %i\n", coins);
}