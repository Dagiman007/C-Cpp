#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"


class Student : public Person
{
    private:
        int student_number;
        string study;
    public:
        Student(int,string);
        virtual ~Student();

        int getStudentNumber();
        string getStudy();
        void setStudentNumber(int);
        void setStudy(string);

        void print();
};

#endif // STUDENT_H
