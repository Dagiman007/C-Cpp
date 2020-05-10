#include "Account.h"

Account::Account(int account_number, double balance, double fee){
    this->account_number = account_number;
    this->balance = balance;
    this->fee = fee;
}
Account::~Account(){
}

int Account::getAccountNumber(){
    return account_number;
}
double Account::getBalance(){
    return balance;
}
double Account::getFee(){
    return fee;
}
void Account::setAccountNumber(int account_number){
    this->account_number = account_number;
}
void Account::setBalance(double balance){
    this->balance = balance;
}
void Account::setFee(double fee){
    this->fee = fee;
}
void Account::deposit(double sum){
    assert(sum>=0);
    setBalance(getBalance()+sum);
}
void Account::withdraw(double sum){
    double tmp = getBalance();
    assert(sum <= tmp);
    setBalance(tmp - sum);
}
void Account::chargeFee(){
    setBalance(getBalance() - getFee());
}
void Account::print(){
    cout << "Account number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
}
void Account::update(){
    cout << "Updating ..." << endl;
}
