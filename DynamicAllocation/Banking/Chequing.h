//
// Created by Adam Saher on 2022-06-04.
//

#ifndef C___CHEQUING_H
#define C___CHEQUING_H


#include "Account.h"

class Chequing : public Account {
    static const unsigned TRANSACTION_FEE, TRANSACTION_LIMIT, MONTHLY_FEE;
    unsigned transactions;
public:
    Chequing(const char*, const char*, const char*, const double&);
    bool deposit(const double&);
    bool withdraw(const double&);
    friend std::ostream& operator<<(std::ostream&, const Chequing&);
};


#endif //C___CHEQUING_H
