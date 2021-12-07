/*
Print a pattern of numbers from  to  as shown below. Each of the numbers is separated by a single space.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() 
{

    int n;
    scanf("%d", &n);
  	
    for (int i = -n + 1; i < n; i++)
    {
        for (int j = -n + 1; j < n; j++)
        {
            printf("%d ", MAX(abs(i), abs(j)) + 1);
        }
        printf("\n");
    } 
      
    return 0;
}
