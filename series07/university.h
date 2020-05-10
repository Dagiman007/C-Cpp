#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

class university
{
    private:
        string name;
        string city;
        int num_students;
    public:
        string getName();
        string getCity();
        int getNumStudents();
        void setName(string name);
        void setCity(string city);
        void setNumStudents(int num_students);
        void graduate();
        void newStudent();

};

#endif // UNIVERSITY_H
