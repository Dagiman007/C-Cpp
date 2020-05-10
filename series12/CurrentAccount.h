#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"


class CurrentAccount : public Account
{
    private:
        double overdraft_limit;
    public:
        CurrentAccount(double);
        virtual ~CurrentAccount();

        double getOverdraftLimit();
        void setOverdraftLimit(double);
        void print();
        void update();
};

#endif // CURRENTACCOUNT_H
