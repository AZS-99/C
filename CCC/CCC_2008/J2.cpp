//
// Created by Adam Saher on 2022-09-09.
//

#include <iostream>
#include <array>
#include "J2.h"

Playlist::Playlist() = default;


void Playlist::run() {
    unsigned button, presses;
    std::array<char, 2> tmp;
    do {
        std::cout << "Button number: ";
        std::cin >> button;
        std::cout << std::endl << "Number of presses: ";
        std::cin >> presses;

        if (button == 1) {
            for (auto i = 0u; i < presses; ++i) {
                playlist.push_back(playlist.front());
                playlist.pop_front();
            }
        } else if (button == 2) {
            for (auto i = 0u; i < presses; ++i) {
                playlist.push_front(playlist.back());
                playlist.pop_back();
            }
        } else if (button == 3) {
            for (auto i = 0u; i < presses; ++i) {
                tmp[0] = playlist.front();
                playlist.pop_front();
                tmp[1] = playlist.front();
                playlist.pop_front();
                for (auto j = 1u; j >= 0u; --j) playlist.push_front(tmp[j]);
            }
        }
    } while(button != 4);

    for (auto& element: playlist) std::cout << element << ' ';

}
