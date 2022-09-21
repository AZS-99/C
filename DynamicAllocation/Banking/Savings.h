//
// Created by Adam Saher on 2022-07-26.
//

#ifndef C_SAVINGS_H
#define C_SAVINGS_H

#include "Account.h"

const unsigned SAVINGS_TRANSACTION_LIMIT = 1;
const double SAVINGS_TRANSACTION_FEE = 0.5;

class Savings : public Account {
public:
    Savings(const char* first_name, const char* surname, const char* sin, const double& balance = 0);
    bool withdraw(const double&);
    bool deposit(const double&);
    std::ostream& print(std::ostream& os) const;
};





#endif //C_SAVINGS_H
