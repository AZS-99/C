//
// Created by Adam Saher on 2022-06-29.
//

#include "Autoshop.h"

sdds::Autoshop &sdds::Autoshop::operator+=(sdds::Vehicle *theVehicle) {
    m_vehicles.push_back(theVehicle);
}

void sdds::Autoshop::display(std::ostream &out) const {
    for (const auto& vehicle: m_vehicles) {
        vehicle->display(out);
        out << std::endl;
    }
}

sdds::Autoshop::~Autoshop() {
    for (auto vehicle: m_vehicles)
        delete vehicle;
}


