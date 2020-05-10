#include "university.h"

int main(){
    university university1;
    university1.setName("TU Wien");
    university1.setCity("Wien");
    university1.setNumStudents(1234);

    cout << "Number of students: " << university1.getNumStudents() << " in " << university1.getName() << endl;
    cout << "How many graduated?" << endl;
    int n;
    cin >> n;
    for(int i = 0 ;i<n;i++){
        university1.graduate();
    }
    cout << "Updated number of students: " << university1.getNumStudents();
}


void university::graduate(){
    assert(getNumStudents() > 0);
    this->num_students -= 1;
}
void university::newStudent(){
    this->num_students += 1;
}

string university::getName(){
    return name;
}
string university::getCity(){
    return city;
}
int university::getNumStudents(){
    return num_students;
}

void university::setName(string name){
    this->name = name;
}
void university::setCity(string city){
    this->city = city;
}
void university::setNumStudents(int num_students){
    this->num_students = num_students;
}
