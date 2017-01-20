#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 80
void squeeze(char s1[], char s2[]); 
//int pow(int a, int base);
/* print longest input line */
char line[MAXLINE];
 
int main() { 
	char f [7] = {'h','i','r','o','m','u','\0'};
	char g [10] = {'d','u','c','k','y','m','o','m','o','\0'};
	squeeze(f,g);
	printf(" this is the string %s", f);
	
} 
void squeeze(char s1[], char s2[]) { 
	int i = 0;
	int j = 0; 
	int k = 0;
	while(s2[i] != '\0') {
		if(strchr(s1, s2[i]) >= 0) {
			for(j = k = 0; s1[j] != '\0'; j++) {
				if(s1[k] != s2[i]) {
					s1[k++] = s1[j];
				}
			}
			s1[k] = '\0';
		}
		i++;
	}
}

