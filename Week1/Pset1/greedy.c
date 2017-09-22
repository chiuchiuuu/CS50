#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int change;
    int coin_num = 0;
    printf("O hai! ");
    do{
        printf("How much change is owed?\n");
        change = round(get_float() * 100);
    }while(change < 0);
    
    int quaters = change / 25;
    coin_num += quaters;
    change %= 25;
    
    int dimes = change / 10;
    coin_num += dimes;
    change %= 10;
    
    int nickels = change / 5;
    coin_num += nickels;
    change %= 5;
    
    int pennies = change / 1;
    coin_num += pennies;
    
    printf("%i\n", coin_num);
    
}
