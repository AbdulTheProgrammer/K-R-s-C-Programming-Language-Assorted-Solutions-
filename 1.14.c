#include <stdio.h> 

/* replaces \b \t amd \\ to make more explicit */
#define IN 1 
#define OUT 0

int array[256];

int main() { 
	int characters, i, j;
	

	while((characters = getchar()) != EOF)  {
		array[characters]++;	
			
	}
	printf("\n HISTOGRAM \n");
	for (i =0; i<256;i++) {
	
		if(array[i]) {
			printf("%3c",  i);
			for(j=0;j<array[i];j++) {
				putchar('|');
			}
			putchar('\n');
		}
	}
} 
