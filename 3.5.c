#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void itob(int n, char s[], int b);
 
int main() {
    char empty[100];
    itob(2346, empty, 16);
    printf("%s \n", empty);
    
}
//integer to string conversion from a given base
void itob(int n, char s[], int b) {
    int rem, i,j, temp;
    i = 0;
    while (n) {
        rem = n % b;
        if(rem > 9) {
            s[i++] = rem-10 + 'A';
        }
        else {
          s[i++] = rem + '0';
        }
        n /= b;
    }
    s[i--] = '\0';
    for(j =0; j < i; j++, i--)
        temp = s[i], s[i] = s[j], s[j] = temp;
}
