//
// Created by Adam Saher on 2022-08-21.
//

#ifndef C_S2_H
#define C_S2_H

#include <string>
#include <vector>
#include <unordered_map>

/*

Problem Description
The CEMC is organizing a workshop with an activity involving pairs of students. They decided to assign partners ahead of
time. You need to determine if they did this consistently. That is, whenever A is a partner of B, then B is also a
partner of A, and no one is a partner of themselves.

Input Specification
The input consists of three lines. The first line consists of an integer N (1 < N ≤ 30), which is the number of students
in the class. The second line contains the first names of the N students sep- arated by single spaces. (Names contain
only uppercase or lowercase letters, and no two students have the same first name). The third line contains the same N
names in some order, separated by single spaces.
The positions of the names in the last two lines indicate the assignment of partners: the ith name on the second line is
the assigned partner of the ith name on the third line.

Output Specification
The output will be good if the two lists of names are arranged consistently, and bad if the arrangement of partners is
not consistent.

Sample Input 1
4
Ada Alan Grace John
John Grace Alan Ada

Output for Sample Input 1
good

Explanation for Output for Sample Input 1
Ada and John are partners, and Alan and Grace are partners. This arrangement is consistent.


Sample Input 2
7
Rich Graeme Michelle Sandy Vlado Ron Jacob
Ron Vlado Sandy Michelle Rich Graeme Jacob

Output for Sample Input 2
bad

Explanation for Output for Sample Input 2
Graeme is partnered with Vlado, but Vlado is partnered with Rich. This is not consistent. It is also inconsistent
because Jacob is partnered with himself.


Sample Input 3
26
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
Z Y X W V U T S R Q P O N M L K J I H G F E D C B A

Sample output 3
good
 */

class S2 {
    std::vector<std::string> friends1, friends2;
    std::unordered_map<std::string, std::string> map;
    unsigned count;
public:
    S2();
    bool is_consistent();
};


#endif //C_S2_H
