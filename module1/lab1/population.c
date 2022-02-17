#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ss;
    do
    {
        ss = get_int("Start size: ");
    }
    while (ss < 9);

    int es;
    do
    {
        es = get_int("End size: ");
    }
    while (es <= ss);

    int y = 0;

    while (ss != es)
    {
        ss = ss + (ss / 3) - (ss / 4);
        y++;
    }
    printf("Years: %i\n", y);
}
