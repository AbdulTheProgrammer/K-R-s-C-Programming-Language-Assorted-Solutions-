#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 80
void escape(char s[] , char t[]);
void rev_escape(char s[] , char t[]);
//unsigned  pow(unsigned  a, unsigned  base);
/* prunsigned  longest input line */
char line[MAXLINE];
 
int main() {
	char v[10000];
	char s[10000];
	int c;
	int i =0;
	while((c=getchar()) != EOF && i != 10000) { 
		v[i++] = c; 
	}
	v[i] = '\0';
	escape(s,v); 
	printf("this is the string %s \n", s); 
	rev_escape(v,s); 
	printf("this is the string %s \n", v); 
	
	return 0;
}

void escape(char s[], char t[]) {
	int i;
	int j;
	for(j = i =0; t[i] != '\0';i++) {
		switch(t[i]) {
			case '\n': 
				s[j++] = '\\'; 
				s[j++] = 'n';
				break; 
			case '\t':
				s[j++] = '\\'; 
				s[j++] = 't'; 
				s[j] = 'n';
				break;
			default: 
				s[j++] = t[i];
				break;			
		}
		
	}
	s[j] = '\0';
}
void rev_escape(char s[], char t[]) {
	int i;
	int j;
	for(j = i =0; t[i] != '\0';i++) {
		switch(t[i]) {
			case '\\': 
				switch (t[i+1]) {
					case 'n': 
						s[j++] = '\n';
						i++;
						break;
					case 't': 
						s[j++] = '\t';
						i++;
						break;
					default: 
						s[j++] = t[i];
						break;
				}
				break; 
			default: 
				s[j++] = t[i];
				break;			
		}
		
	}
	s[j] = '\0';
	
}