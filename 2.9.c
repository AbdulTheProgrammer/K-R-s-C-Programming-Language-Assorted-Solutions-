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
/* x &= (x-1) deletes the rightmost 1 bit 
if odd -> case is simple and after operation new value = x-1. 
if even -> x-1 results in the rightmost zero becoming 1 and the the rightmost 1 becoming zero
then the & operation zeros out both these bits, therefore the rightmost 1 bit is deleted from x. 
*/
int bitcount(unsigned x) {
	int b; 
		
	for(b = 0; x != 0; x &= (x-1) { 
		if(x & 01) 
			b++;
	}
	return b;

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


