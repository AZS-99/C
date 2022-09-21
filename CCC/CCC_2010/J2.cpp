//
// Created by Adam Saher on 2022-04-18.
//

#include <iostream>
#include "J2.h"

Winner zigzag() {
    unsigned forward1, forward2, back1, back2, steps;
    std::cin >> forward1 >> back1 >> forward2 >> back2 >> steps;

    auto absolute_unit1 = forward1 + back1;
    auto absolute_unit2 = forward2 + back2;
    auto relative_unit1 = forward1 - back1;
    auto relative_unit2 = forward2 - back2;

    auto units1_count = steps / absolute_unit1;
    auto units2_count = steps / absolute_unit2;

    auto relative_distance1 = relative_unit1 * units1_count + steps % absolute_unit1;
    auto relative_distance2 = relative_unit2 * units2_count + steps % absolute_unit2;

    if (relative_distance1 > relative_unit2) return Winner::Byron;
    if (relative_distance2 < relative_unit2) return Winner::Nikky;
    return Winner::Tied;
}
