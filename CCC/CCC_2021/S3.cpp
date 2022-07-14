//
// Created by Adam Saher on 2022-04-14.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "S3.h"


unsigned long student_time_cost(long long p, unsigned w, unsigned r, unsigned c) {
    unsigned long distance = std::abs(p - c);
    return distance > r? (distance - r) * w : 0;
}


unsigned time_cost (const std::vector<unsigned>& weight, const std::vector<unsigned>& radii, unsigned c) {
    unsigned long long total = 0u;
    for (long long int p = 0u; p < weight.size(); ++p) {
        total += student_time_cost(p, weight[p], radii[p], c);
    }
    return total;
}


unsigned min_sum_distances() {
    std::ifstream file("Data/CCC_2021/S3");
    unsigned pupil_count;
    file >> pupil_count;

    unsigned p, w, r, max_p = 0, min_p = 100000000;
    std::vector<unsigned> weight(1000, 0), radii(1000, 0);
    std::vector<unsigned> positions(pupil_count);
    for (auto i = 0u; i < pupil_count; ++i) {
        file >> p >> w >> r;
        positions[i] = p;
        weight[p] = w;
        radii[p] = r;
        if (p > max_p) max_p = p;
        if (p < min_p) min_p = p;
    }
    weight.resize(max_p + 1);
    radii.resize(max_p + 1);




    auto min_distance = std::numeric_limits<unsigned long>::max();
    auto chosen_p = 0;

    auto mid = (max_p + 1 + min_p) / 2;
    for (auto i = min_p; i < max_p + 1; ++i) {
        auto distances_from_p = time_cost(weight, radii, i);
//        std::cout << "distance from " << i << " = " << distances_from_p << std::endl;
        if (distances_from_p < min_distance) {
            min_distance = distances_from_p;
            chosen_p = i;
        }
    }
    std::cout << "min reached at p = " << chosen_p << std::endl;
    return min_distance;
}