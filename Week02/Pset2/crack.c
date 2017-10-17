#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    char password[5];
    char salt[3] = {argv[1][0], argv[1][1], '\0'}; // salt is the first two characters in hashed password
    
    //four nested four loop two decrypt the password
    for (password[0] = 'A'; password[0] <= 'z'; password[0] == 'Z'? password[0] = 'a' : password[0]++ ) //iterate over 'A' to 'Z' and 'a' to 'z'
    {
        //one character
        password[1] = '\0';
        if (strcmp(argv[1], crypt(password, salt)) == 0)
        {
            printf("%s\n", password);
            return 0;
        }
        for (password[1] = 'A'; password[1] <= 'z'; password[1] == 'Z'? password[1] = 'a' : password[1]++ )
        {
            //two characters
            password[2] = '\0';
            if (strcmp(argv[1], crypt(password, salt)) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
            for (password[2] = 'A'; password[2] <= 'z'; password[2] == 'Z'? password[2] = 'a' : password[2]++ )
            {
                //three characters
                password[3] = '\0';
                if (strcmp(argv[1], crypt(password, salt)) == 0)
                {
                printf("%s\n", password);
                return 0;
                }
                for (password[3] = 'A'; password[3] <= 'z'; password[3] == 'Z' ? password[3] = 'a' : password[3]++)
                {
                    //four characters
                    password[4] = '\0';
                    if (strcmp(argv[1], crypt(password, salt)) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                }
            }
        }
    }
}
