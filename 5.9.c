#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define BUFSIZE 100
int bufp = 0;
int buf[BUFSIZE];
int  day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    printf("%i \n",day_of_year(1989,1,2));
}
static char daytab[2][13] = {{0,31,28,31,30,31,30,31,30,31,30,31,30},
                            {0,31,29,31,30,31,30,31,30,31,30,31,30}
};

int  day_of_year(int year, int month, int day) {
    int i, leap;
    char *p;
    leap = ((year%4 ==0 && year%100 != 0) || (year%400 ==0));
    p = &daytab[leap][0];;
    for (i =0; i < month; i++)
        day += *(p+i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, day, leap;
    char *p;
    leap = ((year%4 ==0 && year%100 != 0) || (year%400 ==0));
    p = &daytab[leap][0];;
    for (i =1; yearday > daytab[leap][i]; i++)
        yearday -= *(p+i);
    *pmonth = i;
    *pday = yearday;
}


