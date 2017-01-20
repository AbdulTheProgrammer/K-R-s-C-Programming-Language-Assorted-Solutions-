#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 80
int any(char s1[], char s2[]); 
//int pow(int a, int base);
/* print longest input line */
char line[MAXLINE];
 
int main() { 
	char f [7] = {'h','i','r','o','m','u','\0'};
	char g [10] = {'d','u','c','k','y','m','o','m','o','\0'};
	printf(" this is any's output %i", any(f,g));
	
}
/*
	takes 2 strings, returns the position of the first character match in s1, 
	no null/error input checks, 
	returns -1 if no match occured
*/ 
int any(char s1[], char s2[]) { 
	int i; 
	int j;
	for(j = 0; s2[j] != '\0'; j++) {
		for(i = 0;s1[i] != '\0';i++ ) {
			if (s1[i] == s2[j]) 
				return i;
		}
	}
	return -1;
}

