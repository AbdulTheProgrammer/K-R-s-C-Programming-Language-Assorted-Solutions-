#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 80
unsigned setbits(unsigned x, int p, int n, unsigned y); 
void binary_print(int a);  
//int pow(int a, int base);
/* print longest input line */
char line[MAXLINE];
 
int main() {
	unsigned a = 21; 
	unsigned b = 777;
	binary_print(a); 
	binary_print(b);
	binary_print(setbits(b,5,3,a));
}
unsigned setbits(unsigned x, int p, int n, unsigned y) {
	int mask = (~(~0 << n))<<(p+1-n); 
	// clear all bits except copy bits and move to correct position	
	y = ((~(~0 << n))&y)<< (p+1-n); 
	x &= ~mask;
	x |= y;
	return x;

}
void binary_print(int x) { 
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


