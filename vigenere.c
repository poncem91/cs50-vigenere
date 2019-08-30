#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//program that encrypts messages using Vigenere’s cipher

int main(int argc, string argv[])
{
    if (argc != 2) //make sure only one more argument added
    {
        printf("Error\n");
        return 1;
    }

    string k = argv[1];

    for (int i = 0; i < strlen(k); i++)
    {
        if (isalpha(k[i]) == 0) //checks if letter is not in alphabet
        {
            printf("Error\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: "); //gets initial message

    printf("ciphertext: ");
    for (int i = 0, j = 0, len = strlen(k); i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i])) //checks if letter in alphabet
        {
            if (isupper(plaintext[i])) //encrypts if uppercase
            {
                printf("%c", (((plaintext[i] - 65 + tolower(k[j]) - 97) % 26) + 65));
                if (j == len - 1) //resets cycle if at end of key
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }

            else if (islower(plaintext[i])) //encrypts if lowercase
            {
                printf("%c", (((plaintext[i] - 97 + tolower(k[j]) - 97) % 26) + 97));
                if (j == len - 1) //resets cycle if at end of key
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }
        }
        else
        {
            printf("%c", plaintext[i]); //leaves non-alpha as is
        }
    }
    printf("\n");
    return 0;
}