//
// Created by Adam Saher on 2022-09-05.
//

#ifndef C_J3_H
#define C_J3_H


#include <unordered_map>
#include <string>

/*
Problem J3: GPS Text Entry
Problem Description
For her birthday, Sandy got a Global Positioning System (GPS) unit, which is an electronic device she can use to track
the local hiking trails. Along the way Sandy can mark waypoints that can be recorded on a map when she gets home. A
description of each waypoint can be entered in the unit, however the device does not have a keypad. Instead, it has four
cursor buttons, up, down, left, and right, and a button to accept the letter. The keypad looks like the following:
                                                  ^
                                             << accept >>
                                                  edges

The screen displays a grid of the letters and symbols that can be used to “type out” the description.
Here is the layout of the grid:
                                        A   B   C   D   E   F
                                        G   H   I   J   K   L
                                        M   N   O   P   Q   R
                                        S   T   U   V   W   X
                                        Y   Z space -   . enter

When you enter the name of the waypoint, the cursor starts at the A. You must move the cursor to the location of the
next letter or symbol and then accept that letter. The cursor can only move to squares which are adjacent horizontally
or vertically (not diagonally). Once you have entered all the letters in the description, you need to move the cursor to
”enter” and accept the entire phrase.

You are to write a program that will calculate the number of cursor movements it takes to “type in” a phrase. For
example, to enter the word “GPS”, starting from the “A” position, you would move down 1 to select “G”, then move right 3
and down 1 to select “P”, then move down 1 and left 3 to select “S” and finally move down 1 and right 5 to select
“enter”. This is a total of 15 cursor movements. Note that the total number of cursor movements does not change if you
choose to move down and then across or across and then down. Also note that you cannot move beyond the boundaries of the
grid (e.g., you cannot move off the grid nor “wrap-around” the grid).

Input Specification
The input for your program will be a string of at most 40 characters. You may assume that all characters in the string
are contained in the grid.

Output Specification
The output for your program will be an integer that is the total number of cursor movements needed to enter the string
using the grid layout given.

Sample Input 1
GPS
Output for Sample Input 1
15

Sample Input 2
ECHO ROCK
Output for Sample Input 2
29
 */

class AlphaGrid {
    unsigned moves_count;
    std::unordered_map<std::string, std::array<int, 2>> alpha_map;
public:
    AlphaGrid();
};


#endif //C_J3_H
