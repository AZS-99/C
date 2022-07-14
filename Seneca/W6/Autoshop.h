//
// Created by Adam Saher on 2022-06-29.
//

#ifndef C___AUTOSHOP_H
#define C___AUTOSHOP_H


#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
    class Autoshop {
        std::vector<Vehicle*> m_vehicles;
    public:
        ~Autoshop();
        Autoshop& operator+=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        template <typename T>
        void select(T test, std::list<const Vehicle*>& vehicles);
    };

    template<typename T>
    void sdds::Autoshop::select(T test, std::list<const Vehicle*>& vehicles) {
        for (auto vehicle: m_vehicles)
            if (test(vehicle)) vehicles.push_back(vehicle);
    }
}




#endif //C___AUTOSHOP_H
