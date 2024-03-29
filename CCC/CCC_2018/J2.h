//
// Created by Adam Saher on 2022-08-19.
//

#ifndef C_J2_H
#define C_J2_H

/*
Problem J2: Occupy parking Problem Description
You supervise a small parking lot which has N parking spaces.
Yesterday, you recorded which parking spaces were occupied by cars and which were empty. Today, you recorded the same
information.
How many of the parking spaces were occupied both yesterday and today?

Input Specification
The first line of input contains the integer N (1 ≤ N ≤ 100). The second and third lines of input contain N characters
each. The second line of input records the information about yesterday’s parking spaces, and the third line of input
records the information about today’s parking spaces. Each of these 2N characters will either be C to indicate an
occupied space or . to indicate it was an empty parking space.

Output Specification
Output the number of parking spaces which were occupied yesterday and today.

Sample Input 1
5
CC..C
.CC..
Output for Sample Input 1
1

Explanation of Output for Sample Input 1
Only the second parking space from the left was occupied yesterday and today.

Sample Input 2
7
CCCCCCC
C.C.C.C
Output for Sample Input 2
4
Explanation of Output for Sample Input 2
The first, third, fifth, and seventh parking spaces were occupied yesterday and today.

 */

unsigned common_car_spots();


#endif //C_J2_H
