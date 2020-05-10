#include <stdio.h>
#include <stdlib.h>
#include "datum.h"

struct _Date_{
    int day;
    int month;
    int year;
};

typedef struct _Date_ Date;

int main(){
    Date *date = newDate(23,6,1995);
    if(isMeaningful(date) == 1)
        printf("Yup meaningful!!!");
    else
        printf("Nope");
}

Date* newDate(int d, int m, int y){
    Date* date = malloc(sizeof(Date));
    date->day = d;
    date->month = m;
    date->year = y;

    return date;
}

int isMeaningful(Date* date){
    int d = getDateDay(date);
    int m = getDateMonth(date);
    int y = getDateYear(date);
    if((d > 31)&&(d < 1) && (m > 12)&&(m < 1)&&(y < 0))
        return 0;
    else if(isLeapYear(y) == 0 && m == 2 && d != 28)
        return 0;
    else if(isLeapYear(y) == 1 && m == 2 && d != 29)
        return 0;
    else
        return 1;
}

void setDateDay(Date* date, int d){
    date->day = d;
}
void setDateMonth(Date* date, int m){
    date->month = m;
}
void setDateYear(Date* date, int y){
    date->year = y;
}

int getDateDay(Date* date){
    return date->day;
}
int getDateMonth(Date* date){
    return date->month;
}
int getDateYear(Date* date){
    return date->year;
}

int isLeapYear(int y){
    if((y%4 == 0 && y % 100 != 0)||(y % 400 == 0))
        return 1;
    else
        return 0;
}
