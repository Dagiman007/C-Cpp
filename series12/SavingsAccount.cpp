#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(double interest_rate){
    this->interest_rate = interest_rate;
}

SavingsAccount::~SavingsAccount(){
}

void SavingsAccount::addInterest(){
    double temp = getBalance()*(1 + getInterestRate()*12);
    setBalance(getBalance() + temp);
}
double SavingsAccount::getInterestRate(){
    return interest_rate;
}
void SavingsAccount::setInterestRate(double interest_rate){
    this->interest_rate = interest_rate;
}

void SavingsAccount::print(){
    cout << "Account number: " << getAccountNumber() << endl;
    cout << "Balance: " << getBalance() << endl;
    cout << "Interest rate: " << interest_rate << endl;
}
void SavingsAccount::update(){
    this->addInterest();
}
