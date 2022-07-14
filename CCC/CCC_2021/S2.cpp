//
// Created by Adam Saher on 2022-04-18.
//

#include <fstream>
#include <vector>
#include <iostream>
#include "S2.h"

Board::Board() {
    std::ifstream file("Data/CCC_2021/S2");

    file >> rows >> cols >> instructions;
    std::vector<bool> flipped_r(rows, false), flipped_c(cols, false);

    char ch;
    unsigned j;
    for (auto i = 0u; i < instructions; ++i) {
        file >> ch >> j;
        if (ch == 'R') flipped_r[j] == !flipped_r[j];
        else if (ch == 'C') flipped_c[j] == !flipped_c[j];
    }

    return;
}
