//
// Created by Adam Saher on 2022-05-16.
//

#ifndef CCC_J4_H
#define CCC_J4_H
/*
Problem Description
Valentina wants books on a shelf to be arranged in a particular way. Every time she sees a shelf of books, she
rearranges the books so that all the large books appear on the left, followed by all the medium-sized books, and then
all the small books on the right. She does this by repeatedly choosing any two books and exchanging their locations.
Exchanging the locations of two books is called a swap.
Help Valentina determine the fewest number of swaps needed to arrange a shelf of books as she wishes.

Input Specification
The input will consist of exactly one line containing at least one character. The following table shows how the
available 15 marks are distributed.

Output Specification
Output a single integer which is equal to the minimum possible number of swaps needed to arrange the books so that all
occurrences of L come first, followed by all occurrences of M, and then all occurrences of S.

Sample Input 1
LMMMS
Output for Sample Input 1
0

Explanation of Output for Sample Input 1
The books are already arranged according to Valentina’s wishes.

Sample Input 2
LLSLM
Output for Sample Input 2
2

Explanation of Output for Sample Input 2
By swapping the S and M, we end up with LLMLS. Then the M can be swapped with the L to its right. This is one way to use
two swaps to arrange the books as Valentina wants them to be. It is not possible to use fewer swaps because both S and M
need to be moved but using one swap to exchange them does not leave the books arranged as Valentina wants them to be.

Sample Input 3
LSSLLSLSLSSSSLSLLSLSSSSLSLLLLSLSSLLSLSSLSLLLSLSSLLSSSLLLSSLSSLLSSSLSLSSLSSLSLSLLLLSSSLLSLLSSSSLLLSLS
Output for Sample Input 3
25

Sample Input 4
MSLLLLSLMLLMSSLMMMMSSSMSSSSMSSMMMMSSSMMSSMSLLMMLSMSLMMSLLMSSMMLMMSSMLLSSLMLMLMMSSLLLLSLLMLSMSMLMMMMSSMMSSSMMLMLLMMSLLLMSSLSLMSLLMSSLMSLMMMMMMSMMLMSLSSSMSLLLLMLMLLSSMSMLLSMLLLLMLLMSLSMMMLSMMMLSLLMSSMSLSSMLLSLMMSMSSLSMMMMLMLMMLSSSSSSLLMSMLSSSMMLLMMLSLLLLSSLLMMLSSMLLLLLMSSLMMMSLLLSLSMMLMLLLMMSSLMSSLMSMMMLSLMLMMLSLSMLMSMSMSMMMLSLMLSLLSMSSSMMLMLMLSSMLMSSMMSMMSSMLSSSSMSMLMLSMMLSMMSMLSMSLMMSLLMSLSLLLSMLSSLLSSLLSMMLSMSSMMLSSLMMLMLMMLMSMMMMSMSMSMMLLLMSSMLLMMSSSMLSSSLSSMMMSLLLSSMMSLMMSLMMSLSLMLSMMSSLMSMSLMMLMMSSSSLLSSMSMSLLSLMMSMLMLLLSSLSSLSSLLSMLLSLSMMSLSMLMSLMMMMLSLSMLMLSSSMSMSLMSLSLSSMSLSSMSSSLSSLMMLLSSLLSLSMMMMMLSSSMLMMMSSLMLMSSLMSLSSSSSMLSSMSSLLLLLLLMMLLLMLSMMLLSLSLMMSSLSLMMMSLSLLLMLMMMLSLMSMSMLMLSSSSSLSSSSLMMMSSSLMLLSMLSSSMLLMLMSLLMMMMSMLLSMSLMLSLLSMSSLLMMLLMLSMLLSLSLSSLSMSLMLSSLSLMMMLSLLSLSLLMSMLMLSSLMMLMLMSLMLLMMSMMLMLMMMMSLLMSSMLSMMSLLSSMLSMLMSLLMLMSMSMMSMSMSLLMSSLSMMMLMLLMSMMMMLLLSMLLSMSLLSSLMSSSMSMMSLLSLLSMSMLSMSMLLLMMLMSMSSSLSLMSMMLLSMLLSMMMLMSLLMMSMMLLLLMSSSMMLLSMSLSMMLMMLLLMSMLMLLS
Output for Sample Input 4
347
*/

#include <string>

class Books {
    unsigned l, m, s;
    std::string line, l_section, m_section, s_section;
public:
    Books();
    unsigned count_swaps();
};


#endif //CCC_J4_H
