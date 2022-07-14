//
// Created by Adam Saher on 2022-07-12.
//

#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include "S3.h"



RestaurantNode::RestaurantNode(const bool& path_node, const bool& visited) {
    distance_from_root = 0u;
    this->path_node = path_node;
    this->visited = visited;
}

std::ostream &operator<<(std::ostream& os, const RestaurantNode& node) {
    return os << (node.path_node? '*' : '0');
}



Pho::Pho() {

    path_nodes_count = 1u;

    std::ifstream file("Data/CCC/2016/S3");
    unsigned restaurant_count, pho_count, tmp1, tmp2;
    file >> restaurant_count >> pho_count;
    restaurants = std::vector<RestaurantNode*>(restaurant_count);

    for (auto i = 0u; i < pho_count; ++i) {
        file >> tmp1;
        restaurants[tmp1] = new RestaurantNode(true);
    }

    root = restaurants[tmp1];
    furthest_node = root;
    root->path_node = true;

    for (auto i = 0u; i < restaurant_count; ++i) {
        if (!restaurants[i]) restaurants[i] = new RestaurantNode(false);
    }

    for (auto i = 0u; i < restaurant_count - 1; ++i) {
        file >> tmp1 >> tmp2;
        restaurants[tmp1]->neighbours.push_back(restaurants[tmp2]);
        restaurants[tmp2]->neighbours.push_back(restaurants[tmp1]);
    }


}


void Pho::mark_path(RestaurantNode* node) {
    node->visited = true;
    if (std::none_of(node->neighbours.cbegin(), node->neighbours.cend(), [](RestaurantNode* neighbour) { return !neighbour->visited; } )) {
        return;
    }

    for (auto neighbour: node->neighbours) {
        if (!neighbour->visited) {
            mark_path(neighbour);
            if (neighbour->path_node) {
                node->path_node = true;
                path_nodes_count++;
            }

        }
    }
}




void Pho::get_diameter(RestaurantNode* node) {
    node->visited = true;

    if (std::none_of(node->neighbours.cbegin(), node->neighbours.cend(), [](RestaurantNode* neighbour) { return neighbour->path_node && !neighbour->visited; } )) {
        return;
    }

    for (auto neighbour: node->neighbours) {
        if (neighbour->path_node && !neighbour->visited) {
            neighbour->distance_from_root = node->distance_from_root + 1;
            if (neighbour->distance_from_root > furthest_node->distance_from_root)
                furthest_node = neighbour;

            get_diameter(neighbour);
        }
    }



}


void Pho::reset() {
    for (auto node: restaurants) {
        node->visited = false;
        node->distance_from_root = 0u;
    }
}


void Pho::run() {
    mark_path(root);

    reset();
    get_diameter(root);
    reset();
    get_diameter(furthest_node);

    std::cout << 2 * (path_nodes_count - 1) - furthest_node->distance_from_root << std::endl;
}


