#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "datum.h"

int getDateYear(Date* date);
typedef struct _Date_ Date;
Date* newDate(int d, int m, int y);

struct _Address_{
    char* street;
    char* number;
    char* city;
    char* zip;
};
typedef struct _Address_ Address;

struct _Person_{
    char* firstname;
    char* surname;
    Address* address;
    Date* birthday;
};
typedef struct _Person_ Person;

int main(){
    Address* addr1;
    addr1->street = "xyz";
    addr1->number = "220";
    addr1->city = "wien";
    addr1->zip = "1110";
    Address* addr2;
    addr2->street = "abc";
    addr2->number = "002";
    addr2->city = "wien";
    addr2->zip = "1010";
    Date *d1 = newDate(23,6,1995);
    Date *d2 = newDate(16,10,1987);
    Person* p1;
    p1->firstname = "J";
    p1->surname = "Bond";
    p1->birthday = d1;
    p1->address = addr1;

    Person* p2 = malloc(sizeof(Person));
    p2->firstname = "M";
    p2->surname = "Corleone";
    p2->birthday = d2;
    p2->address = addr2;

    Person* p = whoIsOlder(p1, p2);

    printf(" %c is older", p->firstname);

}

Person* whoIsOlder(Person* a, Person* b){
    Date* d1;
    Date* d2;
    d1 = getBirthday(a);
    d2 = getBirthday(b);
    int y1 = getDateYear(d1);
    int y2 = getDateYear(d2);
    if(2019 - (y1) > (2019 - y2)){
        return a;
    }else{
        return b;
    }
}

void setFirstName(Person* person, char* fName){
    person->firstname = fName;
}
void setSurName(Person* person, char* sName){
    person->surname = sName;
}
void setAddress(Person* person, Address* addr){
    person->address = addr;
}
void setBirthday(Person* person, Date* dat){
    person->birthday = dat;
}

char* getFirstName(Person* person){
    return person->firstname;
}
char* getSurName(Person* person){
    return person->surname;
}
Address* getAddress(Person* person){
    return person->address;
}
Date* getBirthday(Person* person){
    return person->birthday;
}
