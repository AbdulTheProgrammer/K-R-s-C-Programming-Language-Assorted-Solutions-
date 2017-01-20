#include <stdio.h> 


#define MAXLINE 80
#define MAXSIZE 100
int getline1(char line[], int maxline); 
void copy(char to[], char from[]); 

/* print longest input line */

int main() { 
	int len, index, i; 
	char line[MAXLINE]; 
	char longest[MAXSIZE][MAXLINE]; 
	
	index = 0; 

	while((len = getline1(line, MAXLINE)) > 0) { 
		if(len > MAXLINE) { 
			copy(longest[index],line);
			index++;
		}
	}
	for(i =0;i<=index;i++)
		printf("%s", longest[i]); 
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
