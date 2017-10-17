#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check if command-line input is valid
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    string keyword = argv[1];
    int keyword_len = strlen(keyword);
    for (int i = 0; i < keyword_len; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    printf("plaintext:  ");
    string plaintext = get_string();
    
    printf("ciphertext: ");
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++, j++)
    {
        char letter = plaintext[i];
        int key_index = j % keyword_len;
        int key = isupper(keyword[key_index]) ? keyword[key_index] - 'A' : keyword[key_index] - 'a';  // change letter to number
        
        if (isupper(letter))  //deal with uppercase letter
        {
            printf("%c", 'A' + (letter - 'A' + key) % 26);  // using relative position
        }
        else if (islower(letter))  //deal with lowercase letter
        {
            printf("%c", 'a' + (letter - 'a' + key) % 26);
        }
        else
        {
            printf("%c", letter); //deal with non-alphabetical character
            j--;  // keep key unchanged
        }
    }
    printf("\n");
    return 0;
}
