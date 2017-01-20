#include <stdio.h> 

/* replaces \b \t amd \\ to make more explicit */
#define IN 1 
#define OUT 0

int array[50][2];

int main() { 
	int characters, state, curr_len, index, i,j, word_hit;
	
	state = IN; 
	index =0;
	curr_len =0;

	while((characters = getchar()) != EOF)  {
		
	 	if(characters == '\t' || characters == ' ' || characters == '\n') { 
			state = OUT;
			word_hit =0;
			for(i =0;i <index;i++ ) { 
				if(array[i][0] == curr_len) {
					array[i][1]++;
					word_hit = 1;
					break;
				}
			}
			if(!word_hit && curr_len > 0) { 
				array[index][0] = curr_len;
				array[index][1] = 1;
				index++;
			}	
		}
		else if (state == OUT){ 
			curr_len =0;	
			state = IN;
			putchar('\n');
		}
		if(state == IN) {
			curr_len++;  
			putchar(characters); 
		} 
			
	}
	printf("\n HISTOGRAM \n");
	for (i =0; i<index;i++) {
		printf("%3i", array[i][0]);
		
		for(j=0;j<array[i][1];j++) {
			putchar('|');
		}
		putchar('\n');
	}
} 
