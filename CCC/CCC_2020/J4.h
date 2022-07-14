//
// Created by Adam Saher on 2022-05-16.
//

#ifndef CCC_J4_H
#define CCC_J4_H


#include <string>

class Books {
    unsigned l, m, s;
    std::string line, l_section, m_section, s_section;
public:
    Books();
    unsigned count_swaps();
};


#endif //CCC_J4_H
