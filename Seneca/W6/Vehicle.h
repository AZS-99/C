//
// Created by Adam Saher on 2022-06-28.
//

#ifndef C___VEHICLE_H
#define C___VEHICLE_H
#include <iostream>
#include <string>

namespace sdds {
    class Vehicle {
    public:
        virtual double top_speed() const = 0;
        virtual void display(std::ostream&) const = 0;
        virtual std::string condition() const = 0;
        virtual ~Vehicle() {};
    };
}
#endif //C___VEHICLE_H
