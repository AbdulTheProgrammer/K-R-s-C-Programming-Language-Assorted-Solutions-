#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define swap(t,x,y) { \
            t safe##x##y = x; \
            x = y; \
            y = safe##x##y; \
            }

void itoa1(char s[], int a);
void reverse(char s[]);
int main() {
    char b[100];
    int a = 12345;
    itoa1(b,a);
    reverse(b);
    char c = 'c';
    char d = 'd';
    swap(char, c, d)
    
    printf("this is the string %s %c", b, c);
 }

void itoa1(char s[], int a) {
    static int i = 0;
    if(a < 0) {
        s[i++] = '-';
        a = -a;
    }
    if(a/10) {
        itoa1(s, a/10);
    }
    s[i++] = a % 10 + '0';
    s[i] = '\0';
    
}
void reverse_rec(char  s[], int start, int end) {
    char temp;
    if(start < end) {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        reverse_rec(s, start + 1, end -1);
    }
}
void reverse(char s[]) {
    reverse_rec(s, 0, strlen(s)-1);
}
