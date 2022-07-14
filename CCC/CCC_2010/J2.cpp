//
// Created by Adam Saher on 2022-04-18.
//

#include "J2.h"

bool zigzag_distance(unsigned a, unsigned b, unsigned c, unsigned d, unsigned s) {
    auto segment1 = a - b;
    auto segment2 = c - d;
    auto distance1 = s / segment1 + s % segment1;
    auto distance2 = s / segment2 + s % segment2;
    return distance1 > distance2;
}
