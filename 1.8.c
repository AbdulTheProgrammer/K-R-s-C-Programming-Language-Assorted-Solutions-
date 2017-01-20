#include <stdio.h> 

/* counts blanks, tabs and newlines */

int main() { 
	int characters, blanks, tabs, newlines; 
	
	blanks =0; 
	tabs =0; 
	newlines =0; 
	
	while((characters = getchar()) != EOF)  {
		if(characters == '\n') 
			newlines++; 
		else if(characters == ' ') 
			blanks++; 
		else if(characters == '\t')
			tabs++; 
	}
	printf("blanks: %i, tabs: %i, newlines: %i ", blanks, tabs, newlines); 

} 
