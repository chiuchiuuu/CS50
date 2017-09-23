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
 * using bubble sort
 */
void sort(int values[], int n)
{
    bool flag = true;
    while (flag)
    {
        flag = false; //if no swap, break out the loop
        for (int i = 0; i < n -1; i++)
        {
            if (values[i] > values[i+1])
            {
                flag = true;
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
            }
        }
    }
    return;
}
