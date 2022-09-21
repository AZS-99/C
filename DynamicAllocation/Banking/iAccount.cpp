//
// Created by Adam Saher on 2022-07-26.
//

#include "iAccount.h"
#include "Chequing.h"
#include "Savings.h"

iAccount* create_account(const AccountType& account_type, const char* first_name, const char* surname, const char* sin, const double& amount) {
    iAccount* account = nullptr;
    switch (account_type) {
        case AccountType::chequing:
            account = new Chequing(first_name, surname, sin, amount);
            break;
        case AccountType::savings:
            account = new Savings(first_name, surname, sin, amount);
            break;
        default:
            break;
    }
    return account;
}


std::ostream& operator<<(std::ostream& os, const iAccount* account) {
    account->print(os);
    return os;
}