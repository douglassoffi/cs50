#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Use: ./substitution [KEY]\n");
        return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("Use: ./substitution [KEY]\n");
        return 1;
    }
    string entered_string = argv[1];
    char key[26];
    bool used_already[26];

    for (int i = 0; i < 26; i++)
    {
        used_already[i] = false;
    }
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(entered_string[i]))
        {
            if (isupper(entered_string[i]))
            {
                if (used_already[entered_string[i] - 'A'] == true)
                {
                    printf("Key must not contain duplicate leters: %c\n", entered_string[i]);
                    return 1;
                }
                else
                {
                    used_already[entered_string[i] - 'A'] = true;
                    key[i] = entered_string[i] -'A';
                }
            }
            else
            {
                if (used_already[entered_string[i] - 'a'] == true)
                {
                    printf("Key must not contain duplicate leters: %c\n", entered_string[i]);
                    return 1;
                }
                else
                {
                    used_already[entered_string[i] - 'a'] = true;
                    key[i] = entered_string[i] -'a';
                }
            }
        }
        else
        {
            printf("Please, use only letters\n");
            return 1;
        }
    }
    string plaintext = get_string("plaintext:  ");
    string ciphertext = plaintext;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                ciphertext[i] = (key[plaintext[i] - 'A'] + 'A');
            }
            else
            {
                ciphertext[i] = (key[plaintext[i] - 'a'] + 'a');
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n",  ciphertext);
}