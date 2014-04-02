/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * (needle[value], haystack[values], size[n]) // size is the max number of hay in haystack
 */
bool search(int value, int values[], int n)
{
    if (n < 0)
    {
        return false;
    }
    else 
    {
        //set beginning, middle and last endpoints
        int first, middle, last;
        first = 0;
        last = n-1;
        middle = ((first + last)/2);

        //debugging
        for (int i = 0; i < n; i++)
            printf("\nhaystack[%d] = ", values[i]);
        
        //begin loop
        while (first < last-1)
        {
            //first check is a match!
            if (value == values[middle])
            {
                return true;
            }
            //middle point is less than needle
            else if (values[middle] < value )
            {
                first = middle;
                middle = (first+last)/2;
            }
            //middle point is more than needle 
            else if (values[middle] > value )
            {
                last = middle;
                middle = (first+last)/2;
            }
        }
        
        return (values[first] == value); 
        
    }   
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int x = 0; x < n-1; x++)
	{
		int min = x;
		for (int y = x+1; y < n; y++)
		{
			if (values[min] > values[y])
			{
				min = y;
			}
		}
		int temp = values[x];
		values[x] = values[min];
		values[min] = temp;
	}
}
