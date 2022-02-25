#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (n - x - 2 < y)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}