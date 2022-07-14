//
// Created by Adam Saher on 2022-04-06.
//

#include <array>
#include <algorithm>
#include "S1.h"

/*
IDEA:
Any number greater than 20 could be divided into equal chunks of 20s + remainder.
There are only 2 ways to write a 20: either five 4s or four 5s, lets call them A and B
So, if the number // 20 = restaurants_count, we have restaurants_count + 1 possibilities for arranging those chunks. For instance, take the number 60

60 // 20 = 3

Different ways of arranging 60:
A + A + A
A + A + B
A + B + B
B + B + B

4 ways!
So its the number of chunks of 20s + 1

However, if the remainder is ε [1, 2, 3, 6, 7, 11] (no way to get them using 4s and 5s)
*/

unsigned count_4s_5s(const unsigned& n) {
    std::array<unsigned, 6> zero_values = {{1, 2, 3, 4, 7, 11}};
    return n / 20 + (std::find(zero_values.cbegin(), zero_values.cend(), n % 20) == zero_values.cend()? 1 : 0);
}
