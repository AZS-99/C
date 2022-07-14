//
// Created by Adam Saher on 2022-04-29.
//

#ifndef CCC_S3_DIJKASTRA_H
#define CCC_S3_DIJKASTRA_H


#include <vector>
#include <limits>

class RobotGrid;

class Node {
public:
    char ch;
    unsigned value, x, y;

    Node* left;
    Node* right;
    Node* up;
    Node* down;
    bool visited;
    friend RobotGrid;
    friend std::ostream& operator<<(std::ostream&, const Node&);

    explicit Node(const char& = char{}, unsigned long long = 100);

};


class RobotGrid {
    unsigned rows, cols, size;
    Node* start;
    std::vector<std::vector<Node*>> grid;
    std::vector<Node*> exit_positions, dijkstra_vec;
    std::vector<std::pair<unsigned, unsigned>> cams;

    void block_watched_spots();
public:
    RobotGrid();
    void dijkstra(std::vector<Node*>&);
    friend std::ostream& operator<<(std::ostream&, const RobotGrid&);

};


#endif //CCC_S3_DIJKASTRA_H
