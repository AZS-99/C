//
// Created by Adam Saher on 2022-08-26.
//

#ifndef C_J1_H
#define C_J1_H

#include <string>

/*
Problem Description
You have trouble remembering which type of triangle is which. You write a program to help. Your program reads in three
angles (in degrees).
• If all three angles are 60, output Equilateral.
• If the three angles add up to 180 and exactly two of the angles are the same, output Isosceles.
• If the three angles add up to 180 and no two angles are the same, output Scalene.
• If the three angles do not add up to 180, output Error.

Input Specification
The input consists of three integers, each on a separate line. Each integer will be greater than 0 and less than 180.
Output Specification
Exactly one of Equilateral, Isosceles, Scalene or Error will be printed on one line.

Sample Input 1
60
70
50
Output for Sample Input 1
Scalene

Sample Input 2
60
75
55
Output for Sample Input 2
Error

Sample Input 3
70
40
70
Output for Sample Input 3
Isosceles
 */

enum Triangle : char {
    Scalene = 'S',
    Isosceles = 'I',
    Equilateral = 'E',
    Error = 'R'
};

Triangle triangle_type(const unsigned&, const unsigned&, const unsigned&);

#endif //C_J1_H
