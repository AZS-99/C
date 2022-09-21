//
// Created by Adam Saher on 2022-07-26.
//

#ifndef C_CHEQUING_H
#define C_CHEQUING_H

#include "Account.h"


class Chequing : public Account {
    static const unsigned TRANSACTION_FEE, TRANSACTION_LIMIT, MONTHLY_FEE;

public:
    Chequing(const char*, const char*, const char*, const double&);
    bool deposit(const double&);
    bool withdraw(const double&);
    std::ostream& print(std::ostream& os) const;
};

#endif //C_CHEQUING_H
