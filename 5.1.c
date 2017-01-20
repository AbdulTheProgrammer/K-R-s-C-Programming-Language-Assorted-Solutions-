#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define BUFSIZE 100
int bufp = 0;
int buf[BUFSIZE];

int getch(void);
void ungetch(int);
int getfloat( double *pn);

int main() {
    double val = 0;
    int c;
    while((c = getfloat(&val)) != EOF) {
        switch (c) {
            case '\n':
                printf("this is the double %f", val);
                break;
        }
    }
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
int getfloat(double *pn) {
    int c, sign;
    double deci = 1.0;
    while(isspace(c = getch()));
    
    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1:1;
    if(c == '+' || c == '-')
        c = getch();
    
    if(isdigit(c)) {
        for(*pn = 0.0; isdigit(c); c = getch())
            *pn = 10.0 * *pn + (c-'0');
    }
    else {
        return c;
    }
    
    if(c == '.' && isdigit(c=getch())) {
        for(deci = 1.0; isdigit(c); c=getch()) {
            *pn = 10.0 * *pn + (c-'0');
            deci *= 10.0;
        }
    }
    *pn = sign * *pn / deci;
    if(c != EOF)
        ungetch(c);
    return c;
}
