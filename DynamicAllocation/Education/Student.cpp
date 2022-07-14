//
// Created by Adam Saher on 2022-05-28.
//

#include <cstring>
#include <iomanip>
#include "Student.h"


unsigned education::Student::count = 0u;

education::Student::Student(const char *name, const char* sin) : id(++count){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);

    strcpy(this->sin, sin);
}

std::ostream& education::operator<<(std::ostream& os, const education::Student& student) {
    return os << "Name: " << student.name << std::endl << "id: " << std::setw(10) << std::setfill('0') << student.id;
}
