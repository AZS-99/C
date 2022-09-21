//
// Created by Adam Saher on 2022-05-16.
//

#include <fstream>
#include <iostream>
#include "J4.h"


Books::Books() {
    std::ifstream file("Data/CCC/2021/J4");
    getline(file, line);
    l = std::count(line.cbegin(), line.cend(), 'L');
    m = std::count(line.cbegin(), line.cend(), 'M');
    s = std::count(line.cbegin(), line.cend(), 'S');

    l_section = line.substr(0, l);
    m_section = line.substr(l, m);
    s_section = line.substr(l + m);


}

unsigned Books::count_swaps() {
    auto l_section_Ms = std::count(l_section.cbegin(), l_section.cend(), 'M');
    auto l_section_Ss = std::count(l_section.cbegin(), l_section.cend(), 'S');
    auto m_section_Ls = std::count(m_section.cbegin(), m_section.cend(), 'L');
    auto m_section_Ss = std::count(m_section.cbegin(), m_section.cend(), 'S');
    auto s_section_Ms = std::count(s_section.cbegin(), s_section.cend(), 'M');
    auto s_section_Ls = std::count(s_section.cbegin(), s_section.cend(), 'L');


    auto single_swaps = std::min(l_section_Ss, s_section_Ls) + std::min(l_section_Ms, m_section_Ls) +
            std::min(m_section_Ss, s_section_Ms);


    return  (l_section_Ms + l_section_Ss + m_section_Ss) * 2 - single_swaps;
}
