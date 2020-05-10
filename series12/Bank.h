#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

class Bank
{
    private:
        int n;
        Account* accounts;
    public:
        Bank(int n = 0);
        virtual ~Bank();

        int getSize();
        void setElement(int, Account);
        Account getElement(int);
        void updateAccounts();
};

#endif // BANK_H
