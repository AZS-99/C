//
// Created by Adam Saher on 2022-07-14.
//

#ifndef C_S3_H
#define C_S3_H


#include <fstream>
#include <vector>

class Collision {
    std::vector<bool> gates;
    std::ifstream file;
    unsigned plane_count;
public:
    Collision(const char* filepath);
    unsigned count_till_collision();


};




#endif //C_S3_H
