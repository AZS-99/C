//
// Created by Adam Saher on 2022-05-28.
//

#include <cstring>
#include "School.h"

education::School::School(const char* name) {
    this->name = new char[strlen(name)];
    capacity = 1;
    students = new Student*[capacity]();
    enrolment_count = 0;
}

void education::School::add_student(const char *s_name, const char *sin) {
    auto s = new Student(s_name, sin);
    if (enrolment_count == capacity) enlarge_capacity();
    students[enrolment_count++] = s;
}

void education::School::enlarge_capacity() {
    auto tmp = students;
    students = new Student*[capacity * 2];
    for (auto i = 0u; i < capacity; ++i) students[i] = tmp[i];
    delete[] tmp;
    capacity = capacity * 2;
}

void education::School::list_students() {
    for (auto i = 0u; i < enrolment_count; ++i) std::cout << *students[i] << std::endl;
}




