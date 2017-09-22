#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char encrypt(char letter, int key, int lettercase);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    printf("plaintext:  ");
    string plaintext = get_string();
    int key = atoi(argv[1]) % 26;  //make key from 1 to  26
    
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char letter = plaintext[i];
        if (isupper(letter))  //deal with uppercase letter
        {
            printf("%c", encrypt(letter, key, 1));
        }
        else if (islower(letter))  //deal with lowercase letter
        {
            printf("%c", encrypt(letter,key, 2));
        }
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");
    return 0;
}

char encrypt(char letter, int key, int lettercase)  
{
    // encrypt single letter
    // 1 means uppercase and 2 means lowercase
    
    char std = lettercase == 1 ? 'Z' : 'z';
    
    if (letter + key > std)   // encrypt and return
    {
        return (letter + key - 26);
    }
    else
    {
        return (letter + key);
    }
}
