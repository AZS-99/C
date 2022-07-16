//
// Created by Adam Saher on 2022-07-14.
//

#include "S3.h"

Collision::Collision(const char* filepath) {
    unsigned size, planes_count;
    file = std::ifstream(filepath);
    file >> size;

    gates = std::vector<bool>(size + 1, false);
    gates[0] = true;

    file >> plane_count;



}

unsigned Collision::count_till_collision() {
    unsigned index;
    for (auto i = 0u; i < plane_count; ++i) {
        file >> index;

    }
}
