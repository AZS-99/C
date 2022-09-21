//
// Created by Adam Saher on 2022-07-26.
//

#include "Savings.h"

Savings::Savings(const char* first_name, const char* surname, const char* sin, const double& balance) : Account(first_name, surname, sin, balance){}


bool Savings::withdraw(const double& amount) {
    if (amount + balance > SAVINGS_TRANSACTION_FEE && transactions < SAVINGS_TRANSACTION_LIMIT)
        return Account::withdraw(amount) && ++transactions;
    return false;
}

bool Savings::deposit(const double& amount) {
    balance++;
    return true;
}

std::ostream &Savings::print(std::ostream &os) const {
    return os << balance;
}
