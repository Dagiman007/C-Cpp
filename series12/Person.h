#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        string address;
    public:
        Person(string name ="", string address="");
        virtual ~Person();

        string getName();
        string getAddress();
        void setName(string);
        void setAddress(string);

        virtual void print();
};

#endif // PERSON_H
