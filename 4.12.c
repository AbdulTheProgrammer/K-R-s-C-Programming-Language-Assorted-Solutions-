#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

double atof1(char s[]);
int getop( char s[]);
void push(double);
double pop (void);
int getch(void);
void ungetch(int);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);
int sp = 0;
double val[MAXVAL];
int bufp = 0;
char buf[BUFSIZE];

void print() {
    int i;
    if(sp >= 0) {
        for(i = sp; i > 0;i--) {
            printf("Stack element %i is %f",i,val[i]);
        }
    }
    else {
        printf("stack has no elements");
    }
}
void duplicate() {
    int i;
    int j = sp;
    for(i = 0 ;i <= j;i++) {
        push(val[i]);
    }
}
void swap() {
    double temp;
    if(sp >= 1) {
        temp = val[sp];
        val[sp] = val[sp-1];
        val[sp-1] = temp;
    }
}

/*reverse Polish Calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];
    double vars[26];
    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof1(s));
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap();
                break;
            case 'p':
                print();
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
            case 'S':
                push(sin(pop()));
                break;
            case 'E':
                push(exp(pop()));
                break;
            case 'P':
                op2 = pop();
                push(pow(pop(),op2));
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("divide by zero error");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case '%' :
                op2 = pop();
                push(((int)pop()) % ((int)op2));
                break;
            default:
                printf("error: unknown command %s \n", s);
                break;
        }
    }
    return 0;
}

void push(double f) {
    if(sp<MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full can't push %g \n", f);
}

double pop(void) {
    if(sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
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
int mathfunc(char s[]) {
    if(strcmp(s, "sin") == 0) {
        return 'S';
    }
    else if(strcmp(s, "exp") == 0)
        return 'E';
    else if(strcmp(s, "pow") == 0) {
        return 'P';
    }
    return '\0';
}
/*
int getop (char s[]) {
    int i, c;
    static int prev_c;
    char sign;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    if(!isdigit(c) && !isalpha(c) && c != '.' && c != '-' && c != '+')
        return c;
    i = 0;
    if(c == '-' || c == '+') {
        sign = (c == '-') ? '-':'+';
        if (isdigit((c=getch()))) {
            s[i] = sign;
        }
        else {
            ungetch(c);
            return sign;
        }
        ungetch(c);
    }
    if(isalpha(c)) {
        while(isalpha(s[++i] = c = getch()))
            ;
        ungetch(c);
        s[i] = '\0';
        return mathfunc(s);
    }
    if (isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}*/

int getop (char s[]) {
    int i, c;
    static int prev_c = EOF;
    char sign;
    if( prev_c == EOF || prev_c == '\t' || prev_c == ' ')
        while((s[0] = c = getch()) == ' ' || c == '\t');
    else {
        c = prev_c;
        prev_c = EOF;
    }
    s[1] = '\0';
    
    if(!isdigit(c) && !isalpha(c) && c != '.' && c != '-' && c != '+')
        return c;
    i = 0;
    if(c == '-' || c == '+') {
        sign = (c == '-') ? '-':'+';
        if (isdigit((c=getch()))) {
            s[i] = sign;
        }
        else {
            prev_c = c;
            return sign;
        }
        prev_c = c;
    }
    if(isalpha(c)) {
        if(isalpha(prev_c)) {
            s[++i] = prev_c;
            prev_c = EOF;
            while(isalpha(s[++i] = c = getch()));
        }
        else {
            while(isalpha(s[++i] = c = getch()));
        }
        prev_c = c;
        s[i] = '\0';
        return mathfunc(s);
    }
    if (isdigit(c)) {
        if(isdigit(prev_c)) {
            s[++i] = prev_c;
            prev_c = EOF;
            while(isdigit(s[++i] = c = getch()));
        }
        else {
            while(isdigit(s[++i] = c = getch()));
        }
    }
    if(c == '.') {
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF)
        prev_c = c;
    return NUMBER;
}


double atof1(char s[]) {
    double val, power;
    int i, sign, exp_sign, exp_val;
    
    for(i =0; isspace(s[i]);i++) /* skip whitespace */
        ;
    sign = (s[i] == '-') ? -1: 1;
    
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        
        exp_sign = (s[++i] == '-') ? -1:1;
        
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(exp_val = 0.0; isdigit(s[i]); i++)
            exp_val = 10.0 * exp_val + (s[i] - '0');
        power /= pow(10.0,exp_sign*exp_val);
    }
    return sign * val / power;
}

