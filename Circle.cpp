//
// Created by Adam Saher on 2022-05-14.
//

#include <numbers>
#include <valarray>
#include "Circle.h"


Circle::Circle(const double &radius) {
    this->radius = radius;
}

double Circle::area() const {
    return std::numbers::pi * std::pow(radius, 2);
}

double Circle::circumference() const {
    return 2 * std::numbers::pi * radius;
}


