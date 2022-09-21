//
// Created by Adam Saher on 2022-08-31.
//

#include <iostream>
#include "J3.h"

J3::J3() {
    std::cin >> time;
}

unsigned J3::convert_to_mins() const {
    return time / 100 * 60 + (time % 100) * 60;
}
