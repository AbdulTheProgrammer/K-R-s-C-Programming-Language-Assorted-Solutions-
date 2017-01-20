#include <stdio.h> 


#define MAXLINE 80

int getline1(char line[], int maxline); 
void copy(char to[], char from[]); 
int trim(char line[], char trim_line[]);
void reverse(char line[]);
/* print longest input line */

int main() { 
	int len, max; 
	char line[MAXLINE]; 
	char longest[MAXLINE]; 
	char trim_line[MAXLINE];

	max = 0;
	while((len = getline1(line, MAXLINE)) > 0) { 
		len = trim(line, trim_line);
		if(len > max) { 
			max = len; 
			copy(longest,trim_line);
		}
	}
	reverse(longest); 
	if (max > 0) 
		printf("longest line size is %i, which is %s", max, longest); 
	return 0;
	
} 
void reverse(char line[]) { 
	int i , j;
	char temp[MAXLINE];

	for(i=0; line[i] != '\0'; i++) { 
		temp[i] = line[i]; 
	}

	for(j= i-1; j >=0;j-- ) { 
		line[i-j] = temp[j];
	}
	line[i+1] = '\0';

}
int trim(char line[], char trim_line[]) { 
	int i, j; 
	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t') { 
		i++;
	}
	while(line[i] != '\0') {
		trim_line[j] = line[i];
		j++;
		i++;
	}
	trim_line[j] = '\0';
	return j;
	
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
