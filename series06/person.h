#ifndef HEADER_FILE
#define HEADER_FILE

#include "datum.h"
typedef struct _Date_ Date;
Date* newDate(int d, int m, int y);
typedef struct _Address_ Address;
typedef struct _Person_ Person;


Person* whoIsOlder(Person* a, Person* b);
void setFirstName(Person* person, char* fName);
void setSurName(Person* person, char* sName);
void setAddress(Person* person, Address* addr);
void setBirthday(Person* person, Date* date);
char* getFirstName(Person* person);
char* getSurName(Person* person);
Address* getAddress(Person* person);
Date* getBirthday(Person* person);

#endif
