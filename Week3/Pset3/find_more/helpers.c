/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * using binary search
 */
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    
    int low = 0, high = n - 1, middle;
    while(low <= high)
    {
        middle = (low + high) / 2;
        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] > value)
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 * using counting sort
 */
// maximum amount of hay
#define MAX 65536;
void sort(int values[], int n)
{
    // create a new array, whose indexes is the elements of values
    int keys[MAX] = {0};
    
    // counting keys
    for (int i = 0; i < n; i++)
    {
        keys[values[i]] += 1;
    }
    
    // sort values according to keys array
    for (int i = 0, j = 0; i < MAX; i++)
    {
        // loop until key get down to 0
        while (keys[i] != 0)
        {
            values[j] = i;
            keys[i]--;
            j++;
        }
    }
}
