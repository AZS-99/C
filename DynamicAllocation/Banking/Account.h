//
// Created by Adam Saher on 2022-07-26.
//

#ifndef C_ACCOUNT_H
#define C_ACCOUNT_H


#include <iostream>
#include "iAccount.h"

class Account : public iAccount {
protected:
    double balance;
    const char sin[10];
    char* first_name;
    char* surname;
    unsigned transactions;
public:
    Account(const char*, const char*, const char*, const double& = 0.0);
    bool deposit(const double&) override;
    bool withdraw(const double&);

};



#endif //C_ACCOUNT_H
