//
// Created by Adam Saher on 2022-07-14.
//

#include <fstream>
#include <array>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include "Covid.h"



std::ostream &operator<<(std::ostream& os, const Covid& covid) {
    os << covid.country <<  std::setw(20) << '|' << std::setw(15) << covid.city << '|' << covid.variant << '|' << std::to_string(covid.year);
    os << '|' << std::to_string(covid.cases_count) << '|' << std::to_string(covid.deaths_count);
    return os;
}




CovidCollection::CovidCollection(const char *filename) {
    std::ifstream file(filename);
    std::string line;
    unsigned size;

    while(getline(file, line)) {
        auto covid = new Covid;
        covid->country = line.substr(0, 25);

        size = covid->country.find_last_not_of(' ');
        covid->country.resize(size + 1u);

        covid->city = line.substr(25, 25);
        size = covid->city.find_last_not_of(' ');
        covid->city.resize(size + 1u);

        covid->variant = line.substr(50, 25);
        size = covid->variant.find_last_not_of(' ');
        covid->variant.resize(size + 1u);

        covid->year = stoul(line.substr(75, 5));
        covid->cases_count = stoul(line.substr(80, 5));
        covid->deaths_count = std::stoul(line.substr(85, 5));
        covid_collection.push_back(covid);
    }

}

void CovidCollection::display(std::ostream &out) const {
    std::string line;

    std::for_each(covid_collection.begin(), covid_collection.end(), [&out](Covid* covid) {
        out << *covid << std::endl;
    });

    auto total_cases = std::accumulate(covid_collection.cbegin(), covid_collection.cend(), 0, [](unsigned accumulator, Covid* covid) {
        return accumulator + covid->cases_count;
    });

    auto total_deaths = std::accumulate(covid_collection.cbegin(), covid_collection.cend(), 0, [](unsigned accumulator, Covid* covid) {
        return accumulator + covid->deaths_count;
    });

    std::cout << total_cases << std::endl;
    std::cout << total_deaths << std::endl;



}

void CovidCollection::sort(const std::string& field) {
    std::sort(covid_collection.begin(), covid_collection.end(), [field](Covid* covid1, Covid* covid2) {
        if (field == "country") return covid1->country < covid1->country;
        if (field == "variant") return covid1->variant < covid2->variant;
        if (field == "cases") return covid1->cases_count < covid2->cases_count;
        if (field == "deaths") return covid1->deaths_count < covid2->deaths_count;
    });
}

std::list<Covid> CovidCollection::getListForCountry(const std::string& country) const {
    std::list<Covid*> lst;
    std::list<Covid> lst_static;
    std::copy_if(covid_collection.cbegin(), covid_collection.cend(), lst.begin(), [country] (Covid* covid) {
        return covid->country == country;
    });

    std::transform(lst.begin(), lst.end(), lst_static.begin(), [](Covid* covid) {
        return *covid;
    });

    return lst_static;
}

bool CovidCollection::inCollection(const std::string& variant) const {
    return std::any_of(covid_collection.cbegin(), covid_collection.cend(), [variant]( Covid* covid) {
        return covid->variant == variant;
    });

}

void CovidCollection::cleanList() {
    auto it = covid_collection.begin();
    while (it != covid_collection.end()) {
        it = std::find_if(it, covid_collection.end(), [](Covid* covid) {
            return covid->variant == "[None]";
        });
        if (it != covid_collection.end()) {
            (*it)->variant = "";
        }
    }
}


std::list<Covid> CovidCollection::getListForVariant(const std::string& variant) const {
    std::list<Covid*> lst;
    std::list<Covid> lst_static;
    std::copy_if(covid_collection.cbegin(), covid_collection.cend(), std::back_inserter(lst), [variant] (Covid* covid) {
        return covid->variant == variant;
    });



    std::transform(lst.begin(), lst.end(), std::back_inserter(lst_static), [](Covid* covid) {
        return *covid;
    });

    return lst_static;

    return lst_static;
}






