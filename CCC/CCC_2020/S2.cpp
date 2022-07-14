//
// Created by Adam Saher on 2022-04-17.
//


#include <fstream>
#include <iostream>

#include "S2.h"
#include "../CCC_2018/S3.h"


Grid::Grid() {
    std::ifstream file("Data/CCC_2020/S2");
    file >> m >> n;
    grid = std::vector<std::vector<unsigned>>(m);
    for (auto i = 0u; i < m; ++i) {
        std::vector<unsigned> row(n);
        for (auto j = 0u; j < n; ++j) {
            file >> row[j];
            if (locations.count(row[j]) == 0) {
                auto location = std::make_pair(i, j);
                std::vector<std::pair<unsigned, unsigned>> vec;
                vec.push_back(location);
                locations[row[j]] = vec;
            } else {
                locations[row[j]].push_back(std::make_pair(i, j));
            }
        }
        grid[i] = row;
    }
}




// Initial r = pho_count - 1, initial c = restaurants_count - 1
bool Grid::is_escapable_from(const unsigned& r, const unsigned& c) {
    auto value = (r + 1) * (c + 1);
    if (grid[0][0] == value) return true;
    auto possible_locations = locations[value];
    for (auto& pair: possible_locations) {
        if (is_escapable_from(pair.first, pair.second)) return true;
    }
    return false;
}
