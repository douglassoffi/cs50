#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Use: ./caesar [Key]\n");
                return 1;
            }
        }
        int k = atoi(argv[1]);

        string p = get_string("Plaintext:  ");
        printf("\nCiphertext: ");

        for (int i = 0, n = strlen(p); i < n; i++)
        {
            if (islower(p[i]))
            {
                printf("%c", ((((p[i] - 'a') + k) % 26) + 'a'));
            }
            else if (isupper(p[i]))
            {
                printf("%c", ((((p[i] - 'A') + k) % 26) + 'A'));
            }
            else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Use: ./caesar [Key]\n");
        return 1;
    }
}
