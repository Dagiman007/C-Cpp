#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "Bank.h"
using namespace std;

int main(){
    Account a1(101,120.5,2.5);

    SavingsAccount s1(5.3);
    CurrentAccount c1(500);

    s1.setAccountNumber(102);
    s1.setBalance(1900);
    s1.setFee(2.5);

    c1.setAccountNumber(103);
    c1.setBalance(290);
    c1.setFee(2.5);

    a1.print();
    cout << "Depositing ..." << endl;
    a1.deposit(1900);
    a1.print();

    s1.withdraw(50);
    s1.addInterest();
    c1.chargeFee();

    cout << "Saving account ..." << endl;
    s1.print();
    cout << "Current Balance ..." << endl;
    c1.print();

    Bank b(3);
    b.setElement(0, a1);
    b.setElement(1,s1);
    b.setElement(2,c1);

    b.updateAccounts();
    for(int i=0;i<3;i++)
        b.getElement(i).print();



}

