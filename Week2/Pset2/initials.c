#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string name = get_string();  //ask user to input name
    if (name != NULL)
    {
        if (name[0] != ' ')
        {
            printf("%c", toupper(name[0]));      //check if the first letter valid
        }
        for (int i = 1, n = strlen(name); i < n - 1; i++) //star from 1 to prevent index error
        {
            if( name[i-1] == ' ' && name[i] != ' ')
            {
                printf("%c", toupper(name[i]));
            }
        }
        printf("\n");
    }
}
