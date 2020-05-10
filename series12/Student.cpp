#include "Student.h"


Student::Student(int student_number, string study){
    this->student_number = student_number;
    this->study = study;
}

Student::~Student(){
}


int Student::getStudentNumber(){
    return student_number;
}
string Student::getStudy(){
    return study;
}
void Student::setStudentNumber(int student_number){
    this->student_number = student_number;
}
void Student::setStudy(string study){
    this->study = study;
}

void Student::print(){
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Student number: " << student_number << endl;
    cout << "Study: " << study << endl;
}
