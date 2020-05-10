#ifndef HEADER_FILE
#define HEADER_FILE
#include "person.h"

typedef struct _Date_ Date;
//Date* delDate(Date* date);
extern Date* newDate(int d, int m, int y);
int isMeaningful(Date* date);
void setDateDay(Date* date, int d);
void setDateMonth(Date* date, int m);
void setDateDay(Date* date, int y);
int getDateDay(Date* date);
int getDateMonth(Date* date);
int getDateYear(Date* date);
int isLeapYear(int);

#endif


