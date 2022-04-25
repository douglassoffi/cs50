#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./recover IMAGE");
        return 1;
    }
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open file");
        return 2;
    }

    unsigned char buffer[512];
    int countter = 0;

    FILE *outptr = NULL;

    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", countter);

            outptr = fopen(filename, "w");

            countter++;
        }
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outptr);
        }
    }
    free(filename);
    fclose(outptr);
    fclose(inptr);

    return 0;
}