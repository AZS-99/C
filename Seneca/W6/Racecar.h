//
// Created by Adam Saher on 2022-06-29.
//

#ifndef C___RACECAR_H
#define C___RACECAR_H

#include "Car.h"

namespace sdds {
    class Racecar : public Car {
        double m_booster;
    public:
        Racecar(std::istream&);
        void display(std::ostream& out) const;
        double top_speed() const;
    };
}



#endif //C___RACECAR_H
