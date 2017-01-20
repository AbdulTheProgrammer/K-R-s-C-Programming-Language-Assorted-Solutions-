#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 80
int lower(int c);
//int pow(int a, int base);
/* print longest input line */
char line[MAXLINE];
 
int main() {
	printf("this is lower case %c", lower('Y'));
}
int lower (int c) { 
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A': c; 
}


