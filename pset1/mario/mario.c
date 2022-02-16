#include <cs50.h>
#include <stdio.h>

// Realiza uma pirâmide com "#""
int main(void)
{
    // Solicita valor entre 1 e 8 para definir altura
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;

    for (int i = 0; i < h; i++)
    {

        for (int j = 0; j < h; j++)
        {
            if (h - i - 2< j)
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
