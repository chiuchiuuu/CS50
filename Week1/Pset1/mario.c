#include <cs50.h>
#include <stdio.h>

void print_space(int n);
void print_hash(int n);

int main(void)
{
    int height;
    do{
        printf("Height: ");
        height = get_int();
    }while(height < 0 || height > 23);
    
    for(int i = 0; i < height; i++)
    {
        print_space(height-i-1);
        print_hash(1+i);
        printf("  ");
        print_hash(1+i);
        printf("\n");
    }
    
    
 
}

void print_space(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_hash(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
}
