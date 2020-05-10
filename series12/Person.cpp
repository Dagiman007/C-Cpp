#include "Person.h"


Person::Person(string name, string address){
    this->name = name;
    this->address = address;
}

string Person::getName(){
    return name;
}
string Person::getAddress(){
    return address;
}
void Person::setName(string name){
    this->name = name;
}
void Person::setAddress(string address){
    this->address = address;
}

Person::~Person(){
}

void Person::print(){
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
}
