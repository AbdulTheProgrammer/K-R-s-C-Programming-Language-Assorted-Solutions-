#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void itoa(int n, char s[]);
 
int main() {
    char empty[100];
    itoa(2346, empty);
    printf("%s \n", empty);
    
}
void itoa(int n, char s[]) {
    int i, sign, j, temp;
    
    if((sign = n) < 0) /*record sign */
        n= -n; /*make n positive */
    i=0;
    /* due to 2's complement and the fact that the leftmost bit is the sign bit,
     negation of the largest negative integer will result in the same integer once more. This is because in
     2's complement the range of an signed integer is from -2^(15) - 2^(15)-1. Therefore the abs() function is required
     here
     */
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10));
    if(sign < 0) {
        s[i++] = '-';
    }
    s[i--] = '\0';
    for(j = 0; j < i; i--, j++) {
        temp = s[j], s[j] = s[i], s[i] = temp;
    }
}
