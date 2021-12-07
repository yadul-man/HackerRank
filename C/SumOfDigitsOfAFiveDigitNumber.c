/*
Given a five digit integer, print the sum of its digits.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    int rem;
    
    while (n != 0)
    {
        rem = n % 10;
        sum += rem;
        n /= 10;
    }
    
    printf("%d", sum);
    
    return 0;
}
