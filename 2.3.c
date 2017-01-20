#include <stdio.h> 
#include <math.h>
#include <ctype.h>

#define MAXLINE 80
int htoi(char string[]); 
//int pow(int a, int base);
/* print longest input line */
char line[MAXLINE];
 
int main() { 
	printf(" this is the integer %i",htoi("0xFF"));

	
} 
int htoi(char string[])
{
	int i = 0;
	int integer = 0;
	int base =0;
	if (string[0] == '0' && string[1] == 'x' || string[1] == 'X') 
		i = 2; 
	while(string[i] != '\0') {
		
		if(isdigit(string[i]))
			integer += pow((double)16, (double)base)*(string[i] - '0'); 
		else if (isalpha(tolower(string[i])))  
			integer += pow((double)16, (double)base)*(tolower(string[i]) - 'a' + 10);	
		
		base++;
		i++;
	}
	return integer; 
}
/*
int pow(int a, int base) { 
	int i;
	int num = 1;
	for(i = 0; i < base; i++) { 
		num *= a;
	}
	return num;

}*/
