#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

class Account
{
    private:
        int account_number;
        double balance;
        double fee;
    public:
        Account(int account_number = 0, double balance = 0.0, double fee = 0.0);
        virtual ~Account();

        int getAccountNumber();
        double getBalance();
        double getFee();
        void setAccountNumber(int);
        void setBalance(double);
        void setFee(double);

        void deposit(double);
        void withdraw(double);
        void chargeFee();
        virtual void print();
        virtual void update();
};

#endif // ACCOUNT_H
