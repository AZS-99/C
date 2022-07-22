//
// Created by Adam Saher on 2022-07-18.
//

#include <fstream>
#include <vector>
#include <iostream>
#include "S2.h"

unsigned count_matches(const char* filepath) {
    unsigned jersey_count, athletes_count, athlete_num, success_count = 0;
    char jersey;
    std::ifstream file(filepath);

    file >> jersey_count >> athletes_count;

    std::vector<Sizes> jerseys(jersey_count + 1);

    //Careful! Jerseys start counting from 1
    for (auto i = 1u; i < jersey_count + 1; ++i) {
        file >> jersey;
        jerseys[i] = static_cast<Sizes>(jersey);
    }

    for (auto i = 0u; i < athletes_count; ++i) {
        file >> jersey >> athlete_num;
        if (jerseys[athlete_num] <= static_cast<Sizes>(jersey)) ++success_count;
    }

    return success_count;

}
