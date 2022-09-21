//
// Created by Adam Saher on 2022-07-26.
//

#include "Chequing.h"

const unsigned Chequing::MONTHLY_FEE = 5;
const unsigned Chequing::TRANSACTION_FEE = 1;
const unsigned Chequing::TRANSACTION_LIMIT = 30;

Chequing::Chequing(const char* first_name, const char* surname, const char* sin, const double& balance) : Account(first_name,surname,sin,balance){
    transactions = 0u;
}

std::ostream &operator<<(std::ostream& os, const Chequing& chequing) {
    return os;
}

bool Chequing::deposit(const double &amount) {
    if (transactions < TRANSACTION_LIMIT)
        return Account::deposit(amount) && transactions++;
    else if (amount + balance > TRANSACTION_FEE) {
        return Account::deposit(amount) && Account::withdraw(TRANSACTION_FEE);
    }

    return false;
}

bool Chequing::withdraw(const double& amount) {
    if (transactions < TRANSACTION_LIMIT) return Account::withdraw(amount) && transactions++;
    if (amount + TRANSACTION_FEE <= balance)
        return Account::withdraw(amount + TRANSACTION_FEE);
}

std::ostream& Chequing::print(std::ostream &os) const {
    return os << balance;
}
