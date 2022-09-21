//
// Created by Adam Saher on 2022-08-23.
//

#ifndef C_STRING_H
#define C_STRING_H

#include <iostream>

#include <iostream>

struct String {
    char* data_;
    unsigned size_;
    friend std::ostream& operator<<(std::ostream&, const String&);
public:
    String();
    String(const char*);
    String(const String&);
    String(String&&);
    ~String();
    String& operator=(const String&);
    String& operator=(String&&);
    String& operator+=(const char&);
    String& operator+=(const String&);
    String& append(const char*);
    String& append(const String&);
    String& append(const char&);
    char& back();
    char& front();
    char* data();
    void clear();
    String& insert(const unsigned&, const char&);
    String& insert(const unsigned&, const unsigned&, const char&);
    unsigned size() const;
};


#endif //C_STRING_H
