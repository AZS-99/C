//
// Created by Adam Saher on 2022-04-06.
//


#include <fstream>
#include <vector>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include "S2.h"

std::vector<std::pair<std::string, std::string>> read_constraints(std::ifstream& file) {
    std::string line, pupil1, pupil2;
    getline(file, line);
    auto lines_count = stoi(line);
    std::vector<std::pair<std::string, std::string>> constraints(lines_count);

    for (auto i = 0u; i < lines_count; ++i) {
        getline(file, line);
        std::stringstream ss(line);
        getline(ss, pupil1, ' ');
        getline(ss, pupil2, ' ');
        auto pair = std::make_pair(pupil1, pupil2);
        constraints[i] = pair;
    }
    return constraints;
}



std::unordered_map<std::string, std::string> read_groups(std::ifstream& file) {

    std::string line, pupil1, pupil2, pupil3;

    getline(file, line);
    auto lines_count = stoi(line);
    std::unordered_map<std::string, std::string> groups;


    for (auto i = 0u; i < lines_count; ++i) {
        getline(file, line);
        std::stringstream ss(line);
        getline(ss, pupil1, ' ');
        getline(ss, pupil2, ' ');
        getline(ss, pupil3, ' ');
        groups[pupil1] = pupil2;
        groups[pupil2] = pupil3;
        groups[pupil3] = pupil1;
    }
    return groups;
}





unsigned count_violations(const char* filename) {
    std::ifstream file(filename);

    auto same_groups = read_constraints(file);
    auto not_groups = read_constraints(file);
    auto groups = read_groups(file);
    file.close();

    auto count = 0u;
    count += std::accumulate(same_groups.cbegin(), same_groups.cend(), 0, [&groups](const unsigned& accumulated, const auto& pair){
        if (groups.contains(pair.first) && groups.at(pair.first) == pair.second || groups.contains(pair.second) && groups.at(pair.second) == pair.first)
            return accumulated;
        return accumulated + 1;
    });

    count += std::accumulate(not_groups.cbegin(), not_groups.cend(), 0, [&groups](const unsigned& accumulated, const auto& pair){
        if (groups.contains(pair.first) && groups.at(pair.first) == pair.second || groups.contains(pair.second) && groups.at(pair.second) == pair.first)
            return accumulated + 1;
        return accumulated;
    });
    return count;
}

