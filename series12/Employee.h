#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"


class Employee : public Person
{
    private:
        double salary;
        string job;
    public:
        Employee(double,string);
        virtual ~Employee();

        double getSalary();
        string getJob();
        void setSalary(double);
        void setJob(string);

        void print();
};

#endif // EMPLOYEE_H
