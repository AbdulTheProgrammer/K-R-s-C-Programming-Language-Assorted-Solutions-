#include <stdio.h> 

/* replaces \b \t amd \\ to make more explicit */
#define IN 1 
#define OUT 0

int main() { 
	int characters, state;

	state = IN; 
	while((characters = getchar()) != EOF)  {
		
	 	if(characters == '\t' || characters == ' ' || characters == '\n') { 
			state = OUT;
		}
		else if (state == OUT){ 
			state = IN;
			putchar('\n');
		}
		if(state == IN) { 
			putchar(characters); 
		} 
			
	}
} 
