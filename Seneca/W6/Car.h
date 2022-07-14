//
// Created by Adam Saher on 2022-06-28.
//

#ifndef C___CAR_H
#define C___CAR_H

#include <fstream>
#include <string>

/*
Car Module

This module defines a class that holds information about a single car.

Private Data

Design and code a class named Car, that inherits the interface Vehicle (supplied), and that should be able to store the
following information (for each attribute, you can chose any type you think it's appropriate--you must be able to
justify the decisions you have made):

maker
condition: a car can be new, used, or broken in need of repairs.
top speed
Public Members

a custom constructor that receives an object of type std::istream& as parameter. This constructor should be able to read
a single record from the stream, extract all the information about a single car and store it in the attributes. Each
record has the following format:
TAG,MAKER,CONDITION,TOP_SPEED

TAG, is a single character representing the type of vehicle: c or C for car. Any other tag is considered invalid.
MAKER, the name of the company that makes the car

CONDITION, a single character: n for new, u for used, and b for broken. Any other character is considered invalid.
TOP_SPEED, an integer containing the maximum speed the vehicle can achieve. If the content of this field is not a
number, then the field is considered invalid.
any space at the beginning/end of each field should be removed.
std::string condition() const: a query that returns new, used or broken, representing the condition of the car
double topSpeed() const
void display(std::ostream& out) const, a query that inserts in the first parameter the content of the car object in the
format | MAKER | CONDITION | TOP_SPEED |, where
MAKER, field of size 10
CONDITION, field of size 6
TOP_SPEED, field of size 6, with two significant digits after the period
see alignment in the sample output.
 */

#include "Vehicle.h"

namespace sdds {

    enum class Condition {
        NEW,
        USED,
        BROKEN
    };

    class Car : public Vehicle{
        char* maker;
        Condition condition_;
        double top_speed_;
    public:
        Car(std::istream&);
        ~Car();
        std::string condition() const;
        double top_speed() const;
        void display(std::ostream& out) const;

    };
}



#endif //C___CAR_H
