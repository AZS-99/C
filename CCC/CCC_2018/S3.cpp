//
// Created by Adam Saher on 2022-04-20.
//

#include <vector>
#include <string>
#include <iostream>
#include <limits>

#include "S3.h"


//RobotGrid::RobotGrid() {
//    std::ifstream file("Data/CCC_2018/S3");
//    file >> rows >> cols;
//    grid = std::vector<std::vector<char>>(rows);
//
//    char ch;
//    for (auto i = 0u; i < rows; ++i) {
//        std::vector<char> row(cols);
//        for (auto j = 0u; j < cols; ++j) {
//            file >> row[j];
//            if (row[j] == '.') exit_positions.emplace_back(i, j);
//            if (row[j] == 'C') cams.emplace_back(i, j);
//            else if (row[j] == 'S') start = std::make_pair(i, j);
//        }
//        grid[i] = row;
//    }
//    block_watched_spots();
//
//}
//
//
//void RobotGrid::block_watched_spots() {
//    std::vector<std::pair<unsigned, unsigned>> marked;
//    for (auto& cam: cams) {
//        for (auto c = cam.second + 1; c < cols && grid[cam.first][c] != 'W'; ++c)
//            if (grid[cam.first][c] == '.') {
//                marked.emplace_back(cam.first, c);
//            }
//
//        for (auto c = cam.second - 1; c > -1 && grid[cam.first][c] != 'W'; --c)
//            if (grid[cam.first][c] == '.') {
//                marked.emplace_back(cam.first, c);
//            }
//
//        for (auto r = cam.first + 1; r < rows && grid[r][cam.second] != 'W'; ++r)
//            if (grid[r][cam.second] == '.') {
//                marked.emplace_back(r, cam.second);
//            }
//
//        for (auto r = cam.first - 1; r > -1 && grid[r][cam.second] != 'W'; --r)
//            if (grid[r][cam.second] == '.') {
//                marked.emplace_back(r, cam.second);
//            }
//
//        grid[cam.first][cam.second] = 'W';
//    }
//
//    for (auto& mark: marked){
//        grid[mark.first][mark.second] = 'W';
//    }
//}
//
//
//
//std::vector<std::pair<unsigned, unsigned>> RobotGrid::get_neighbours(const std::pair<unsigned, unsigned>& point) const {
//    auto r = point.first, c = point.second;
//    std::vector<std::pair<unsigned, unsigned>> neighbours;
//    if (r > 0 && (grid[r-1][c] == 'D' || grid[r-1][c] == '.' || grid[r-1][c] == 'S')) neighbours.emplace_back(r-1, c);
//    if (r+1 < rows && (grid[r+1][c] == 'U' || grid[r+1][c] == '.' || grid[r+1][c] == 'S')) neighbours.emplace_back(r+1, c);
//    if (c > 0 && (grid[r][c-1] == 'R' || grid[r][c+1] == '.' || grid[r][c-1] == 'S')) neighbours.emplace_back(r, c-1);
//    if (c+1 < cols && (grid[r][c+1] == 'L' || grid[r][c+1] == '.' || grid[r][c+1] == 'S')) neighbours.emplace_back(r, c+1);
//    return neighbours;
//}
//
//
//
//float RobotGrid::count_steps_to_start(const std::pair<unsigned int, unsigned int>& point) {
//    if (point == start) return 0;
//    if (is_blocked(point)) return std::numeric_limits<float>::infinity();
//
//
//    unsigned r = point.first, c = point.second;
//    bool is_dot = grid[r][c] == '.';
//
//    auto neigbours = get_neighbours(point);
//    auto count =  std::numeric_limits<float>::infinity();
//    for (auto& restaurants_count: neigbours) {
//        if (is_dot) mark(point);
//        auto new_count = count_steps_to_start(restaurants_count);
//        if (is_dot) new_count++;
//        if (new_count < count) {
//            count = new_count;
//        }
//
//    }
//    if (is_dot) unmark(point);
//    return count;
//
//}

//
//std::ostream &operator<<(std::ostream &os, const RobotGrid& g) {
//    for (auto i = 0u; i < g.rows; ++i) {
//        for (auto j = 0u; j < g.cols; ++j)
//            os << g.grid[i][j];
//        os << std::endl;
//    }
//    return os;
//}
//
//void RobotGrid::mark(const std::pair<unsigned int, unsigned int>& point) {
//    if (grid[point.first][point.second] == '.') grid[point.first][point.second] = 'M';
//}
//
//void RobotGrid::unmark(const std::pair<unsigned int, unsigned int>& point) {
//    grid[point.first][point.second] = '.';
//}
//
//bool RobotGrid::is_blocked(const std::pair<unsigned int, unsigned int>& point) const {
//    return grid[point.first][point.second] == 'M' || grid[point.first][point.second] == 'W';
//}
//
//void RobotGrid::output() {
//    for (auto& point: exit_positions) {
//        std::cout << '(' << point.first << ", " << point.second << "): ";
//        std::cout << grid[point.first][point.second];
//        std::cout << count_steps_to_start(point) << std::endl;
//    }
//}



//std::vector<std::pair<unsigned, unsigned>> RobotGrid::get_neighbours(std::pair<unsigned, unsigned> point)  {
//    auto r_min = point.first > 0? point.first - 1 : 0;
//    auto r_max = point.first < rows - 1? point.first + 1 : point.first;
//    auto c_min = point.second > 0? point.second - 1 : 0;
//    auto c_max = point.second < cols - 1? point.second + 1 : point.second;
//
//    std::vector<std::pair<unsigned, unsigned>> neighbours;
//    for (auto r = r_min; r <= r_max; ++r) {
//        for (auto c = c_min; c <= c_max; ++c)
//            if (!(r == point.first && c == point.second) && !grid[r][c].second) {
//                neighbours.emplace_back(r, c);
//            }
//    }
//
//    return neighbours;
//
//}





