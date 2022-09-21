//
// Created by Adam Saher on 2022-07-26.
//

#include <cstring>
#include "Account.h"
Account::Account(const char* first_name, const char* surname, const char* s, const double& balance) : sin {s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8], '\0'} {
    this->balance = balance;

    this->first_name = new char[strlen(first_name)];
    strcpy(this->first_name, first_name);

    this->surname = new char[strlen(surname)];
    strcpy(this->surname, surname);

    transactions = 0u;

}


bool Account::deposit(const double& amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

bool Account::withdraw(const double& amount) {
    if (amount > 0 && amount >= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

//std::ostream &Account::print(std::ostream& os) const {
//    return os << balance;
//}
