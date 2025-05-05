#include <stdio.h>

typedef char *string;

long unsigned int my_strlen(string string);
char my_toupper(char letter);
char my_tolower(char letter);
int isalpha(int character);
int isupper(int character);
int islower(int character);

int main(int argc, string argv[])
{
    // Check if the program was run with one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check if the provided key has exactly 26 characters
    else if (my_strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }
    // Check if all characters in the key are alphabetic
    else
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                if (my_toupper(argv[1][i]) == my_toupper(argv[1][j]))
                {
                    printf("Key must not contain duplicate letters.\n");
                    return 1;
                }
                else
                {
                    continue;
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (isalpha(argv[1][i]) == 0)
            {
                printf("Key must not contain non-alphabetical characters.\n");
                return 1;
            }
        }
    }

    // Get the plaintext from the user
    char plaintext[65536];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    // Create a ciphertext string of the same length as the plaintext
    char ciphertext[my_strlen(plaintext) + 1];
    // Iterate over each character in the plaintext
    for (int i = 0; i < my_strlen(plaintext); i++)
    {
        // If the character is uppercase, convert it using the key
        if (isupper(plaintext[i]) == 1)
        {
            int index = plaintext[i] - 'A';
            ciphertext[i] = my_toupper(argv[1][index]);
        }
        // If the character is lowercase, convert it using the key
        else if (islower(plaintext[i]) == 1)
        {
            int index = plaintext[i] - 'a';
            ciphertext[i] = my_tolower(argv[1][index]);
        }
        // If the character is not a letter, leave it as is
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[my_strlen(plaintext)] = '\0';
    // Print the ciphertext
    printf("ciphertext: %s", ciphertext);
    return 0;
}

long unsigned int my_strlen(string string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
    }
    return i;
}

char my_toupper(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        return (letter - 32);
    }
    return letter;
}

char my_tolower(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return (letter + 32);
    }
    return letter;
}

int isalpha(int character)
{
    if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isupper(int character)
{
    if (character >= 'A' && character <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int islower(int character)
{
    if (character >= 'a' && character <= 'z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
