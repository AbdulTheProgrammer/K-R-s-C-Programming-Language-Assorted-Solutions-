#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 80
unsigned invert(unsigned x, int p, int n); 
void rev_binary_print(int a);  
//int pow(int a, int base);
/* print longest input line */
char line[MAXLINE];
 
int main() {
	unsigned a = 21; 
	unsigned b = 777;
	rev_binary_print(a); 
	rev_binary_print(b);
	rev_binary_print(invert(b,7,3));
}
unsigned invert(unsigned x, int p, int n) {
	int mask = (~(~0<<n))<<(p+1-n); 
	return x ^ mask;
}
void rev_binary_print(int x) { 
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


