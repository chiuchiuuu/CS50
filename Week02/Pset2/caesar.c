#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    printf("plaintext:  ");
    string plaintext = get_string();
    int key = atoi(argv[1]); 
    
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char letter = plaintext[i];
        if (isupper(letter))  //deal with uppercase letter
        {
            printf("%c", 'A' + (plaintext[i] - 'A' + key) % 26);  // using relative position
        }
        else if (islower(letter))  //deal with lowercase letter
        {
            printf("%c", 'a' + (plaintext[i] - 'a' + key) % 26);
        }
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");
    return 0;
}
