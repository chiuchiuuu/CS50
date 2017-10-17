#include <cs50.h>
#include <stdio.h>

int checksum(long long n);
void getCompany(long long n);

int main(void)
{
    
    long long number = 0;
    do{
        printf("Number: ");
        number = get_long_long();
    }while(number <= 0);
    if (checksum(number))
    {
       getCompany(number);
    }
    else
    {
        printf("INVALID\n");
    }
    
    
}

int checksum(long long n)
{
    /* check if the last digit of sum is 0
     * Luhn’s algorithm
     */
    int sum = 0;
    int digits = 1;
    while(n != 0)
    {
        if (digits % 2 == 1)
        {
            sum += n % 10;
            n /= 10;
        }
        else
        {
            int i = n % 10;
            i *= 2;
            sum = sum + i % 10 + i / 10;
            n /= 10;
        }
        digits += 1;
    }
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void getCompany(long long n)
{
    long long number = n;
    int digits = 0;
    while(n != 0)
    {
        n /= 10;
        digits += 1;
    }
   switch (digits)
   {
        case (13):
            if ((int)(number/10e11) == 4)
               {
                   printf("VISA\n");
               }
               break;
        case (15):
            if ((int)(number/10e12) == 34 || (int)(number/10e12) == 37)
            {
                printf("AMEX\n");
            }
            break;
        case (16):{
            int i = number / 10e13;
            if ((int)(number/10e14) == 4)
            {
                printf("VISA\n");
            }
            else if (i == 51 || i == 52 || i == 53 || i == 54 || i == 55)
            {
                printf("MASTERCARD\n");
            }
            break;
        }
   }
}
