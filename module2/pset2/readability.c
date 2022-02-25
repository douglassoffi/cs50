#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    string text = get_string("Text: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isblank(text[i]))
        {
            words++;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    int grade = (int) index;

    if (grade > 1 && grade < 16)
    {
        printf("Grade: %i\n", grade);
    }
    else if (grade > 16)
    {
        printf("Grade: 16+\n");
    }
    else
    {
        printf("Before grade 1\n");
    }
}
