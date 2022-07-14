//
// Created by Adam Saher on 2022-06-28.
//

#include <cstring>
#include <sstream>
#include <array>
#include <iomanip>
#include <regex>
#include "Car.h"

sdds::Car::Car(std::istream& ss) {

    std::string section;

    std::array<std::string, 4> sections;
    for (auto i = 0u; i < 4; ++i) {
        getline(ss, section, ',');
        section = std::regex_replace(section, std::regex(" +$"), "");
        sections[i] = section;

    }

    std::stringstream s2(sections[2]);
    getline(s2 >> std::ws, sections[2]);


    char ch = sections[2][0];
    ch = tolower(ch);

    switch(ch) {
        case 'n':
            condition_ = Condition::NEW;
            break;
        case 'u':
            condition_ = Condition::USED;
            break;
        case 'b':
            condition_ = Condition::BROKEN;
            break;
        case ' ':
            condition_ = Condition::NEW;
            break;
        case '\0':
            condition_ = Condition::NEW;
            break;
        default:
            throw std::invalid_argument("Invalid record! (condition)");

    }

    maker = new char[sections[1].size() + 1];
    strcpy(maker, sections[1].data());
    try {
        top_speed_ = stod(sections[3]);
    } catch (std::exception& e) {
        throw std::invalid_argument("Invalid record! (speed)");
    }
}




std::string sdds::Car::condition() const {
    switch (condition_) {
        case Condition::NEW:
            return {"new"};
        case Condition::BROKEN:
            return {"broken"};
        case Condition::USED:
            return {"used"};
    }
}

double sdds::Car::top_speed() const {
    return top_speed_;
}

void sdds::Car::display(std::ostream &os) const {
    os  <<'|' <<  std::setw(10) << std::right << maker << '|';
    os << std::setw(8) << std::left;
    if (condition_ == Condition::NEW) os << " new";
    else if (condition_ == Condition::BROKEN) os << " broken";
    else if (condition_ == Condition::USED) os << " used";


    os << '|' << std::fixed << std::setprecision(2) << top_speed() << '|';
}

sdds::Car::~Car() {
    delete [] maker;
}


