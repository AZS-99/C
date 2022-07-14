//
// Created by Adam Saher on 2022-07-14.
//

#include <fstream>
#include <array>
#include <sstream>
#include <numeric>
#include <iostream>
#include "Covid.h"



std::ostream &operator<<(std::ostream &, const Covid &) {

}

CovidCollection::CovidCollection(const char *filename) {
    std::ifstream file(filename);
    std::string line;

    while(getline(file, line)) {
        auto covid = new Covid;
        covid->country = line.substr(0, 25);
        auto size = covid->country.find_last_not_of(' ');
        covid->country.resize(size + 1);
        covid->city = line.substr(25, 25);
        covid->variant = line.substr(50, 25);
        covid->year = stoul(line.substr(75, 5));
        covid->cases_count = stoul(line.substr(80, 5));
        covid->deaths_count = std::stoul(line.substr(85, 5));
        covid_collection.push_back(covid);
    }




}

void CovidCollection::display(std::ostream &out) const {
    std::string line;
    std::cout << covid_collection.size() << std::endl;

    line = std::accumulate(covid_collection.cbegin(), covid_collection.cend(), line, [] (std::string l, Covid* covid){
        return l + '\n' + covid->country + '|' + covid->city + '|' + covid->variant + '|' + std::to_string(covid->year)
                    + '|' + std::to_string(covid->cases_count) + '|' + std::to_string(covid->deaths_count);
    });
    std::cout << line << std::endl;
}
