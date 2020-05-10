#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;

class customer
{
    private:
        string name;
        double balance;
        int PIN;
    public:
        void setName(string name);
        void setBalance(double balance);
        void setPIN(int PIN);
        string getName();
        double getBalance();
        int getPIN();
        void printBalance();
        bool checkPIN();
        void drawMoney(double amount);
};

#endif // CUSTOMER_H
