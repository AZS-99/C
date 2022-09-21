//
// Created by Adam Saher on 2022-04-18.
//

/*
Problem Description
Nikky and Byron are playing a silly game in gym class.
Nikky is told by his teacher to walk forward a steps (1 ≤ a ≤ 100) and then walk backward b steps (1 ≤ b ≤ 100), after
which he repeats a forward, b backward, etc. Likewise, Byron is told to walk forward c steps (1 ≤ c ≤ 100) and then walk
backward d steps (1 ≤ d ≤ 100), after which he repeats c forward, d backward, etc. You may assume that a ≥ b and c ≥ d.
Byron and Nikky have the same length of step, and they are required to take their steps simultaneously (that is, Nikky
and Byron will both step forward on their first steps at the same time, and this will continue for each step).
Nikky and Byron start walking from one end of a soccer field. After s steps (1 ≤ s ≤ 10000), the gym teacher will blow
the whistle. Your task is to figure out who has moved the farthest away from the starting position when the whistle is
blown.

Input Specification
The input will be the 5 integers a, b, c, d, and s, each on a separate line.

Output Specification
The output of your program will be one of three possibilities: Nikky if Nikky is farther ahead after s steps are taken;
Byron if Byron is farther ahead after s steps are taken; Tied if Byron and Nikky are at the same distance from their
starting position after s steps are taken.

Sample Input 1
4
2
5
3
12
Output for Sample Input 1
Byron

Explanation of Output for Sample Input
Notice that after 12 steps, Nikky has moved 4 − 2 + 4 − 2 steps, for a total of 4 steps from the starting position,
whereas Byron has moved 5 − 3 + 4 steps, for a total of 6 steps from the starting position. Thus, Byron is ahead.


Sample Input 2
100
1
99
2
9999
Output for Sample Input 2
Nikky


Sample Input 3
10
5
12
5
19
Output for Sample Input 3
Tied


 */

#ifndef CCC_J2_H
#define CCC_J2_H

enum class Winner {
    Byron,
    Nikky,
    Tied
};

Winner zigzag();

#endif //CCC_J2_H
