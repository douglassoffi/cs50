#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_card;
    do
    {
    credit_card = get_long("Credit card number: ");
    }
    while (credit_card < 0);

    int x = 0;
    long y = credit_card;

    while (y > 0)
    {
        y = y / 10;
        x++;
    }

    if (x != 13 && x != 15 && x != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int sum1 = 0;
    int sum2 = 0;
    long z = credit_card;
    int mod1;
    int mod2;
    int total;
    int d1;
    int d2;

    while (z > 0)
    {
        mod1 = z % 10;
        z = z / 10;
        sum1 = sum1 + mod1;

        mod2 = z % 10;
        z = z / 10;

        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    total = sum1 + sum2;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long start = credit_card;

    do
    {
        start = start / 100;
    }
    while (start > 100);

    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
            printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMERICAN EXPRESS\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}