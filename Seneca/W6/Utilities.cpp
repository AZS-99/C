//
// Created by Adam Saher on 2022-06-29.
//


#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
    Vehicle* createInstance(std::istream& file) {
        std::string line, modified;
        getline(file >> std::ws, line);


        std::stringstream ss(line);

        char ch = tolower(line[0]);

        switch (ch) {
            case 'c':
                return new Car(ss);
            case 'r':
                return new Racecar(ss);
            case '\0':
                return nullptr;
            default:
                throw std::invalid_argument(std::string("unrecognised record type"));


        }
    }
}