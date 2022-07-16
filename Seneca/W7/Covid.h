//
// Created by Adam Saher on 2022-07-14.
//

#ifndef C_COVID_H
#define C_COVID_H


#include <string>
#include <vector>
#include <list>

struct Covid {
    std::string country, city, variant;
    unsigned year, deaths_count;
    int cases_count;
};


class CovidCollection {
    std::vector<Covid*> covid_collection;
public:
    CovidCollection(const char* filename);
    bool inCollection(const std::string&) const;
    void display(std::ostream& out) const;
    void sort(const std::string&);
    void cleanList();
    std::list<Covid> getListForCountry(const std::string&) const;
    std::list<Covid> getListForVariant(const std::string&) const;


};

std::ostream& operator<<(std::ostream& out, const Covid& theCovid);




#endif //C_COVID_H
