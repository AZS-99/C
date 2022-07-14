//
// Created by Adam Saher on 2022-05-14.
//

#ifndef C_CIRCLE_H
#define C_CIRCLE_H


class Circle {
    double radius;
public:
    Circle(const double& radius);
    double circumference() const;
    double area() const;
};


#endif //C_CIRCLE_H
