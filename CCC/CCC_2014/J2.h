//
// Created by Adam Saher on 2022-08-26.
//

#ifndef C_J2_H
#define C_J2_H
/*
Problem Description
A vote is held after singer A and singer B compete in the final round of a singing competition. Your job is to count the
votes and determine the outcome.

Input Specification
The input will be two lines. The first line will contain V (1 ≤ V ≤ 15), the total number of votes. The second line of
input will be a sequence of V characters, each of which will be A or B, representing the votes for a particular singer.

Output Specification
The output will be one of three possibilities:
• A, if there are more A votes than B votes;
• B, if there are more B votes than A votes;
• Tie, if there are an equal number of A votes and B votes.

Sample Input 1
6
ABBABB
Output for Sample Input 1
B

Sample Input 2
6
ABBABA
Output for Sample Input 2
Tie
 */

char count_votes();


#endif //C_J2_H
