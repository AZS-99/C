//
// Created by Adam Saher on 2022-07-14.
//

#ifndef C_COVID_H
#define C_COVID_H


#include <string>
#include <vector>

class Covid {
    std::string country, city, variant;
    unsigned year, deaths_count;
    int cases_count;
    friend class CovidCollection;
};


class CovidCollection {
    std::vector<Covid*> covid_collection;
public:
    CovidCollection(const char* filename);
    void display(std::ostream& out) const;

};




#endif //C_COVID_H
