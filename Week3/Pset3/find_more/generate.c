/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // check if getting valid command-line inputs, otherwise, pint error message
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // convert command-line intput(string) to integer
    int n = atoi(argv[1]);

    // initialize before calling drand48()
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));  //seeds the pseudorandom generator drand48()
    }
    else
    {
        srand48((long) time(NULL)); //default argument
    }

    // generate pseudorandom integer with LIMIT
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
