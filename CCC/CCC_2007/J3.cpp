//
// Created by Adam Saher on 2022-09-09.
//

#include <array>
#include <iostream>
#include <vector>
#include "J3.h"
bool deal() {
    unsigned removed_bags_count;
    std::array<unsigned, 10> bags {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
    std::cin >>removed_bags_count;

    std::vector<unsigned> removed_bags(removed_bags_count);
    std::vector<unsigned> remaining_bags(10u - removed_bags_count);

    for (auto i = 0u; i < removed_bags_count; ++i) std::cin >> removed_bags[i];

    std::sort(removed_bags.begin(), removed_bags.end());



}