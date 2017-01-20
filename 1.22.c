#include <stdio.h> 


#define MAXLINE 80
int getline1(void); 

/* print longest input line */
char line[MAXLINE];
 
int main() { 
	int len, i, space; 
	int linemax = 14;
	while((len = getline1()) > 0) { 
			i =0;
			while( line[i] != '\0') { 
				if (line[i] == ' ') { 
					space = i;
				} 
				if(i > linemax) { 
					line[space] = '\n'; 
					linemax *= 2; 
				}
				i++;
			}
			printf("%s", line);

	} 

	
} 
int getline1(void)
{
  int c, i;
  extern char line[];
  
  for ( i=0;i<MAXLINE-1 && ( c=getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if(c == '\n') 
    {
      line[i] = c;
      ++i;
    }
  line[i] = '\0';
  return i;

}
