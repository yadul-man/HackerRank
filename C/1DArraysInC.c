/*
Create an array of size n dynamically, and read the values from stdin. 
Iterate the array calculating the sum of all elements. Print the sum and free the memory where the array is stored.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, sum = 0;
    
    scanf("%d",&n);
    
    int *val = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
        sum += val[i];
    }
    
    printf("%i", sum);
    
    free(val);  
     
    return 0;
}
