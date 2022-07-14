//
// Created by Adam Saher on 2022-05-28.
//

#ifndef C___SCHOOL_H
#define C___SCHOOL_H


#include "Student.h"
namespace education {
    class School {
        char* name;
        Student** students;                 // There isn't, and there should not be, an empty constructor for Student.
        unsigned enrolment_count, capacity;

        void enlarge_capacity();
    public:
        School(const char* name);
        void add_student(const char* name, const char* sin);
        void list_students();
    };

}


#endif //C___SCHOOL_H
