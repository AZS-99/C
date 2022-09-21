//
// Created by Adam Saher on 2022-08-29.
//

#include <iostream>
#include <string>
#include "J5_S3.h"

LetterNode::LetterNode() = default;


Roads::Roads() {
    for (auto i = 0u; i < 26; ++i) nodes[i] = new LetterNode;
    std::string line;
    unsigned index1, index2;
    std::cin >> line;
    while (line != "**") {

        index1 = (int) line[0] - 'A';
        index2 = (int) line[1] - 'A';
        nodes[index1]->neighbours.push_back(nodes[index2]);
        nodes[index2]->neighbours.push_back(nodes[index1]);
        std::cin >> line;
    }
    nodes[0]->on_path = true;\
    mark_path_to_destination(nodes[1], nodes[0]);

    for (auto i = 0u; i < nodes.size(); ++i)
        if (nodes[i]->on_path) std::cout << (char) (i + 'A') << ' ';
}

void Roads::mark_path_to_destination(LetterNode* src, LetterNode* destination) {

    src->visited = true;
    for (auto neighbour: src->neighbours) {
        if (!neighbour->visited) {
            mark_path_to_destination(neighbour, destination);
            if (neighbour->on_path) src->on_path = true;
        }
    }
}




