//
// Created by Adam Saher on 2022-05-28.
//

#ifndef C___STUDENT_H
#define C___STUDENT_H

#include <string>
#include <iostream>

namespace education {
    class Student {
        char* name;
        char sin[10];
        const unsigned id;
        static unsigned count;
    public:
        Student(const char* name, const char* sin);
        friend std::ostream& operator<<(std::ostream&, const Student&);
    };
}




#endif //C___STUDENT_H
