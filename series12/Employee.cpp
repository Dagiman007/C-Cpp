#include "Employee.h"


Employee::Employee(double salary = 0, string job = ""){
    this->salary = salary;
    this->job = job;
}

Employee::~Employee(){
}


double Employee::getSalary(){
    return salary;
}
string Employee::getJob(){
    return job;
}
void Employee::setSalary(double salary){
    this->salary = salary;
}
void Employee::setJob(string job){
    this->job = job;
}

void Employee::print(){
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Job: " << job << endl;
    cout << "Salary: " << salary << endl;
}
