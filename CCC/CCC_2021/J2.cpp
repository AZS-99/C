//
// Created by Adam Saher on 2022-08-23.
//

#include <iostream>
#include <fstream>
#include "J2.h"

std::string get_highest_bidder() {
    std::ifstream file("Data/CCC/2021/J2");
    unsigned bidders_count, bid, highest_bid;
    std::string bidder, highest_bidder;


    file >> bidders_count;
    highest_bid = 0u;

    for (auto i = 0u; i < bidders_count; ++i) {
        file >> bidder >> bid;
        if (bid > highest_bid) {
            highest_bid = bid;
            highest_bidder = bidder;
        }
    }
    return highest_bidder;
}
