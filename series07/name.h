#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <string.h>
#include<cstdio>
#include <cstddef>
#include <cstring>

using namespace std;

class name
{
    private:
        string first_name;
        string surname;
    public:
        void setFirstName(string first_name);
        void setSurname(string surname);
        string getFirstName();
        string getSurname();
        void printName();
        void setFullName(string fullName);
};

#endif // NAME_H
