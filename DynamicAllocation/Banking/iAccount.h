//
// Created by Adam Saher on 2022-07-26.
//

#ifndef C_IACCOUNT_H
#define C_IACCOUNT_H


#include <iostream>

enum class AccountType {
    chequing,
    savings
};


class iAccount {
public:
    virtual bool withdraw(const double&) = 0;
    virtual bool deposit(const double&) = 0;
    virtual std::ostream& print(std::ostream&) const = 0;
    friend std::ostream& operator<<(std::ostream&, const iAccount*); //A friend fn can't be virtual, since it doesn't belong.
};

// Constructors can't be virtual. why?!
// Abstract classes can neither be passed as parameters, nor used as return type, but we can use their pointers instead
iAccount* create_account(const AccountType&, const char*, const char*, const char*, const double& = 0.0) ;


/*
 All classes that come before the first one that has an implementation for all the pure virtual methods in the
 interface, are abstract.
 */



#endif //C_IACCOUNT_H
