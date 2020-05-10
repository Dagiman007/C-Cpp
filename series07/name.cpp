#include "name.h"

int main(){
    name n1;
    string fullName;
    cout << "Enter your full name: " << endl;
    getline(cin, fullName);
    n1.setFullName(fullName);
    n1.printName();
}

void name::setFirstName(string first_name){
    this->first_name = first_name;
}
void name::setSurname(string surname){
    this->surname = surname;
}
string name::getFirstName(){
    return this->first_name;
}
string name::getSurname(){
    return this->surname;
}

void name::setFullName(string fullName){
    size_t found = fullName.find_last_of(' ');   //size_t is an unsigned integral type

	setFirstName(fullName.substr(0,found));
	setSurname(fullName.substr(found+1));
}

void name::printName(){
	int i = 0;
	int n = 0;
	string firstName;

	string fname = getFirstName();

	n = fname.length();

	firstName = fname.substr(0, fname.find(' '));

	cout << firstName << " ";

	for(i = 0; i < n; i++){
		if(fname[i] == ' '){
			cout << fname[i+1] << ". ";
		}
	}
	cout << surname << endl;

}
