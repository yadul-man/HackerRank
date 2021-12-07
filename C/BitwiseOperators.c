/*
You will be given an integer n, and a threshold, k. 
For each number i from 1 through n, find the maximum value of the logical and, or and xor when compared against all integers n that are greater than i.
Consider a value only if the comparison returns results less than k.
Print the results of the and, or and exclusive or comparisons on separate lines, in that order.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k)
{
    int and = 0, or = 0, xor = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((i & j) > and && (i & j) < k)
                and = i & j;
            
            if((i | j) > or && (i | j) < k)
                or = i | j;
            
            if((i ^ j) > xor && (i ^ j) < k)
                xor = i ^ j;
        }
    } 
    
    printf("%d\n%d\n%d\n", and, or, xor);
}

int main()
{
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
