#include "customer.h"

int main(){
    customer c1;
    c1.setName("Bond.");
    c1.setBalance(120);
    c1.setPIN(0000);

    double amount;
    cout << "Withdrawal amount: " << endl;
    cin >> amount;
    c1.drawMoney(amount);

    cout << "Updated balance: " << c1.getBalance();
}

void customer::setName(string name){
    this->name = name;
}
void customer::setBalance(double balance){
    this->balance = balance;
}
void customer::setPIN(int PIN){
    this->PIN = PIN;
}
string customer::getName(){
    return this->name;
}
double customer::getBalance(){
    return this->balance;
}
int customer::getPIN(){
    return this->PIN;
}
void customer::printBalance(){
    cout << "Current balance: " << getBalance() << endl;
}
bool customer::checkPIN(){
    int PIN;
    cout << "Enter PIN code: ";
    cin >> PIN;
    assert(PIN >= 0);
    if(getPIN() == PIN){
        return true;
    }else{
        return false;
    }
}
void customer::drawMoney(double amount = 0.0){
    if(checkPIN()){
        assert(amount > 0 && amount < balance);
        setBalance(balance - amount);
        if(getBalance() < 10)
            cout << "\nWarning!!! Less balance." << endl;
    }else{
        cout << "\nWrong PIN code" << endl;
    }
}
