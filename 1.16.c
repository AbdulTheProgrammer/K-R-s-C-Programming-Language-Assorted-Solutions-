#include <stdio.h> 


#define MAXLINE 10

int getline1(char line[], int maxline); 
void copy(char to[], char from[]); 

/* print longest input line */

int main() { 
	int len, max; 
	char line[MAXLINE]; 
	char longest[MAXLINE]; 
	
	max = 0;
	while((len = getline1(line, MAXLINE)) > 0) { 
		if(len > max) { 
			max = len; 
			copy(longest,line);
		}
	}
	if (max > 0) 
		printf("longest line size is %i, which is %s", max, longest); 
	return 0;
	
} 

int getline1(char s[], int lim) { 
	int c , i; 
	
	for(i=0;(c=getchar()) != EOF && c != '\n'; i++) { 
		if (i < lim-1) 
			s[i] = c;

	}
	if(c == '\n' && i < lim-1) { 
		s[i] = c; 
		++i;
		s[i] = '\0';
	}
	else {
		s[lim-1] = '\0'; 
	}
	return i; 
}

void copy(char to[], char from[]) { 
	int i; 
	i = 0;
	
	while((to[i] = from[i]) != '\0') { 
		++i; 
	}
}
