#include <stdio.h> 
#include <math.h>
#include <ctype.h>
#include <string.h>
void expand(char s1[], char s2[]);
 
int main() {
    char t1[7] = {'a', '-','z','0','-','9', '\0'};
    char t2[6] = {'-','0','-','9','-','\0'};
    char t3[6] = {'a','-','b','-','c','\0'};
    char empty[100];
    expand(t1,empty);
    printf("%s \n", empty);
    expand(t2,empty);
    printf("%s \n", empty);
    expand(t3,empty);
    printf("%s \n", empty);
    
}

void expand(char s1[], char s2[]) {
    int i = 0;
    int j = 0;
    int c;
    if(s1[0] == '-') {
        s2[0] = s1[0];
        i++;
        j++;
    }
    for(; s1[i] != '\0';i++) {
        if(s1[i] == '-' && s1[i + 1] != '\0') {
            if(isdigit(s1[i - 1]) && isdigit(s1[i + 1]) && s1[i - 1] <= s1[i + 1]) {
                c = s1[i - 1];
                if(i-2 >=0 && s1[i-2] == '-') {
                    c++;
                }
                while(c != s1[i + 1]) {
                    s2[j++] = c++;
                }
                s2[j++] = s1[i + 1];
            }
            else if(isalpha(s1[i - 1]) && isalpha(s1[i + 1]) && s1[i - 1] <= s1[i + 1]) {
                c = s1[i - 1];
                if(i-2 >=0 && s1[i-2] == '-') {
                    c++;
                }
                while(c != s1[i + 1]) {
                    s2[j++] = c++;
                }
                s2[j++] = s1[i + 1];
            }
        }
        else if(s1[i] == '-' && s1[i+1] == '\0')
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}
