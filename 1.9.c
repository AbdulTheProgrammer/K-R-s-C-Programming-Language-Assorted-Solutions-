#include <stdio.h> 

/* counts blanks, tabs and newlines */

int main() { 
	int characters, blank; 
		
	blank = 0;
	while((characters = getchar()) != EOF)  {
		if(characters == ' ') { 
			blank = 1;
		}
		if(blank && characters != ' ') { 
			putchar(' '); 
			blank =0;
		}
		if(!blank) { 
			putchar(characters);
		}
	
	}} 
