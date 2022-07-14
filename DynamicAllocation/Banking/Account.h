//
// Created by Adam Saher on 2022-06-04.
//

#ifndef C___ACCOUNT_H
#define C___ACCOUNT_H


#include <iostream>

class Account {
protected:
    double balance;
    const char sin[10];
    char* first_name;
    char* surname;
public:
    Account(const char*, const char*, const char*, const double& = 0.0);
    bool deposit(const double&);
    bool withdraw(const double&);
    friend std::ostream& operator<<(std::ostream&, const Account&);

};


#endif //C___ACCOUNT_H
