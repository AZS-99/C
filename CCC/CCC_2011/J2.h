//
// Created by Adam Saher on 2022-08-19.
//

#ifndef C_J2_H
#define C_J2_H

/*

Problem Description
Margaret has looked at the wind floating over the prairies for a long time. After these observations, she has created a
formula that will describe the altitude of a weather balloon launched from her house. In particular, her equation
predicts the altitude A (in metres above the ground) at hour t after launching her balloon is:
                                    A = −6t^4 + ht^3 + 2t^2 + t
where houses_count is an integer value representing the humidity as a value between 0 and 100 inclusive.
Margaret is curious at what the earliest hour is (if any) that her weather balloon will hit the ground after launch, so
long as it is no more than the maximum time, M, that Margaret is willing to wait. You can assume that the weather
balloon touches ground when A ≤ 0.

In order to do this, your program should use the formula to calculate the altitude when t = 1, t = 2, and so on, until
the balloon touches the ground or t = M is reached.

Input Specification
The input is two non-negative integers: houses_count, the humidity factor, followed by M, the maximum number of hours Margaret will
wait for the weather balloon to return to ground. You can assume 0 ≤ houses_count ≤ 100 and 0 < M < 240.

Output Specification
The output will be one of the following possibilities:
• The balloon does not touch ground in the given time.
• The balloon first touches ground at hour: T
where T is a positive integer value representing the earliest hour when the balloon has altitude less than or equal to
zero.

Sample Input 1
30
10
Output for Sample Input 1
The balloon first touches ground at hour:
6

Sample Input 2
70
10
Output for Sample Input 2
The balloon does not touch ground in the given time.
*/


class J2 {
    unsigned humidity;
    unsigned max_hrs;
public:
    J2();
    unsigned can_land_on_time() const;
};


#endif //C_J2_H
