#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(double overdraft_limit){
    this->overdraft_limit = overdraft_limit;
}

CurrentAccount::~CurrentAccount(){
}

double CurrentAccount::getOverdraftLimit(){
    return overdraft_limit;
}
void CurrentAccount::setOverdraftLimit(double overdraft_limit){
    this->overdraft_limit = overdraft_limit;
}

void CurrentAccount::print(){
    cout << "Account number: " << getAccountNumber() << endl;
    cout << "Balance: " << getBalance() << endl;
    cout << "Overdraft limit: " << overdraft_limit << endl;
}
void CurrentAccount::update(){
    cout << "\nOverdraft: " << overdraft_limit << endl;
}
