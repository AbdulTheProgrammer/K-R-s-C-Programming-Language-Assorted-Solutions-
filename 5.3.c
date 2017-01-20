#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define BUFSIZE 100
int bufp = 0;
int buf[BUFSIZE];

void strcat1(char *s, char *t);
int strend1(char *s, char *t);
char* strncpy1(char *des, const char * source, size_t num);
void strncat1(char *s1, const char *s2, size_t n);
int strncmp1(const char * str1, const char * str2, size_t num );

int main() {
    char a[100] = {'a','b','c','\0'};
    char b[] = "efg";
    char c[] = "abc";
    int eq;
    //strcat1(a,b);
    strncpy1(a,b,3);
    eq = strend1(a,c);
    printf("this is the string %s eq = %i \n", a, eq);
}
char * strncpy1(char *des, const char * source, size_t num) {
    char *start = des;
    while((*des++ = *source++) && --num);
    if(*--des && num) {
        while(--num)
            *des++ = 0;
    }
    return start;
}
void strcat1(char *s, char *t) {
    if(*s == '\0')
        return;
    while(*(++s));
    while((*s++ = *t++));
}
int strend1(char *s, char *t) {
    s += strlen(s) -strlen(t);
    while(*s++ == *t++);
    if(!*--s)
        return 1;
    return 0;
}
void strncat1(char *s, const char *s2, size_t n) {
    while(*++s);
    while((*s++ = *s2++) && --n);
}

int strncmp1(const char * str1, const char * str2, size_t num )
{
    while(*str1++ == *str2++ && --num);
    if(!*str1-- || !num)
        return 1;
    return 0;
}



