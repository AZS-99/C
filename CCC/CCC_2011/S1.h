//
// Created by Adam Saher on 2022-07-16.
//

#ifndef C_S1_H
#define C_S1_H
/*
Problem Description
You would like to do some experiments in natural language processing. Natural language processing (NLP) involves using
machines to recognize human languages.

Your first idea is to write a program that can distinguish English text from French text.
After some analysis, you have concluded that a very reasonable way of distinguishing these two languages is to compare
the occurrences of the letters “t” and “T” to the occurrences of the letters “s” and “S”. Specifically:
• if the given text has more “t” and “T” characters than “s” and “S” characters, we will say that it is (probably)
English text;
• if the given text has more “s” and ”S” characters than “t” and “T” characters, we will say that it is (probably)
French text;
• if the number of “t” and “T” characters is the same as the number of “s” and “S” characters, we will say that it is
(probably) French text.

Input Specification
The input will contain the number N (0 < N < 10000) followed by N lines of text, where each line has at least one
character and no more than 100 characters.

Output Specification
Your output will be one line. This line will either consist of the word English (indicating the text is probably
English) or French (indicating the text is probably French).

Sample Input 1
3
The red cat sat on the mat.
Why are you so sad cat?
Don’t ask that.

Output for Sample Input 1
English

Sample Input 2
3
Lorsque j’avais six ans j’ai vu, une fois,
une magnifique image,
dans un livre

Output for Sample Input 2
French
 */

bool is_english(const char*);


#endif //C_S1_H
