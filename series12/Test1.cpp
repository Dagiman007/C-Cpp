#include "Person.h"
#include "Employee.h"
#include "Student.h"
using std::cout;
using std::endl;

int main(){
    Person p("James bond", "london");
    Employee e(1200,"Assassin");
    Student s(1234,"Engineering");

    p.print();

    e.setName("Caesar");
    e.setAddress("Rome");
    s.setName("Khalessi");
    s.setAddress("Essos");

    e.print();
    s.print();
}
