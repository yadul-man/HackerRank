/*
You have to print the character, ch, in the first line. Then print s in next line. In the last line print the sentence, sen.

Input Format

First, take a character, ch as input.
Then take the string, s as input.
Lastly, take the sentence sen as input.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch, s[100], sen[100];
    
    scanf("%c", &ch);
    printf("%c\n",ch);
    
    scanf("%s",s);
    printf("%s\n",s);
    
    scanf("\n");
    
    scanf("%[^\n]%*c", sen);
    printf("%s\n",sen);
    return 0;
}
