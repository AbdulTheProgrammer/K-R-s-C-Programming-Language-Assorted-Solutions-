#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 80
unsigned rightrot(unsigned x, int n); 
void rev_binary_print(unsigned a);  
//int pow(int a, int base);
/* print longest input line */
char line[MAXLINE];
 
int main() {
	unsigned a = 21; 
	unsigned b = 777;
	rev_binary_print(a); 
	rev_binary_print(b);
	rev_binary_print(rightrot(b,1));
}
//assuming 32 bit integers
unsigned rightrot(unsigned x, int n) { 
	return (x >> n)| (x << (32 - n)); 
}

void rev_binary_print(unsigned x) { 
	int rem = 0;
	if(!x) { 
		printf("0");
	}
	while(x) { 
		rem = x%2; 
		x /= 2; 
		printf("%i", rem); 
	}
	printf("\n"); 
}


