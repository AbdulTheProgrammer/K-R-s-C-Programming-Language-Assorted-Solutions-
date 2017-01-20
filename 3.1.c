#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 80
unsigned long binsearch(long unsigned  x, long unsigned  v[], long unsigned  n); 
void rev_binary_prunsigned (unsigned a);  
//unsigned  pow(unsigned  a, unsigned  base);
/* prunsigned  longest input line */
char line[MAXLINE];
 
int main() {
	long unsigned  v[10000];
	for(long unsigned  i =0; i < 10000; i++) { 
		v[i] = i;
	}
	printf("This is the output from gprof %i ", binsearch(11, v, 10000));
	return 0;
}

unsigned long binsearch(unsigned long x, long unsigned  v[], long unsigned  n) 
{ 
	long unsigned  low, high, mid; 
	low = 0;
	high = n - 1;
	mid = (low+high)/2; 
	while (low <= high && v[mid] != x) { 
		if(x < v[mid]) 
			high = mid - 1; 
		else if(x > v[mid])
			low = mid + 1; 
		mid = (low+high)/2; 
	}
	return v[mid] == x ? mid : -1; 
}
