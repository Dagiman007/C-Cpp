#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"


class SavingsAccount : public Account
{
    private:
        double interest_rate;
    public:
        SavingsAccount(double interest_rate = 0.0);
        virtual ~SavingsAccount();

        void addInterest();
        double getInterestRate();
        void setInterestRate(double);
        void print();
        void update();
};

#endif // SAVINGSACCOUNT_H
