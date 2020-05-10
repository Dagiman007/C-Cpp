#include "Bank.h"
#include <cassert>

Bank::Bank(int n){
    this->n = n;
    accounts = new Account[n];
}

Bank::~Bank(){
    delete [] accounts;
    accounts = NULL;
}

int Bank::getSize(){
    return n;
}

void Bank::setElement(int i, Account a){
    assert(i >= 0 && i < n);
    accounts[i] = a;
}
Account Bank::getElement(int i){
    assert(i>=0 && i<n);
    return accounts[i];
}

void Bank::updateAccounts(){
    for(int i=0;n;i++){
        accounts[i].chargeFee();
        accounts[i].update();
    }
}
