//
// Created by Adam Saher on 2022-06-29.
//

#include "Racecar.h"

sdds::Racecar::Racecar(std::istream& ss) : Car(ss){
    std::string tmp;
    getline(ss, tmp);
    m_booster = stod(tmp);

}

void sdds::Racecar::display(std::ostream &out) const {
    Car::display(out);
    out << '*';
}

double sdds::Racecar::top_speed() const {
    return Car::top_speed() * (1 + m_booster);
}


