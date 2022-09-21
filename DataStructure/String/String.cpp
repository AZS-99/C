//
// Created by Adam Saher on 2022-09-10.
//

#include <cstring>
#include "String.h"

String::String() {
    data_ = nullptr;
    size_ = 0u;
}

String::String(const char* string){
    size_ = strlen(string);
    this->data_ = new char[size_+1];
    std::strcpy(this->data_, string);

}

String::String(const String& src) {
    size_ = src.size_;
    data_ = new char[size_+1];
    strcpy(data_, src.data_);
}

String::String(String&& src) {
    size_ = src.size_;
    data_ = src.data_;

    src.data_ = nullptr;
    src.size_ = 0u;
}

String::~String() {
    delete[] data_;
}

String& String::operator=(const String& src) {
    delete[] data_;
    size_ = src.size_;
    data_ = new char[size_ + 1];
    strcpy(data_, src.data_);
    return *this;
}

String& String::operator=(String&& src) {
    delete[] data_;
    size_ = src.size_;
    data_ = src.data_;
    src.data_ = nullptr;
    src.size_ = 0u;
    return *this;
}

String& String::operator+=(const char& src) {
    if (src == '\0') return *this;
    if (data_ == nullptr){
        data_ = new char[2];
        data_[0] = src;
        data_[1] = '\0';
        size_ = 2u;
        return *this;
    }

    char* datacpy = new char[size_+2];
    strcpy(datacpy, data_);

    datacpy[size_] = src;
    datacpy[size_+1] = '\0';

    delete[] data_;
    data_= datacpy;

    size_ += 2;

    return *this;
}

String& String::operator+=(const String& src) {

}

String& String::append(const char& string) {
    if (string == '\0') return *this;
    if (data_ == nullptr){
        data_ = new char[2];
        data_[0] = string;
        data_[1] = '\0';
        size_ = 2u;
        return *this;
    }

    char* datacpy = new char[size_+2];
    strcpy(datacpy, data_);

    datacpy[size_] = string;
    datacpy[size_+1] = '\0';

    delete[] data_;
    data_= new char[size_+2];
    strcpy(data_, datacpy);
    delete[] datacpy;

    size_ += 2;

    return *this;
}

String& String::append(const char* string) {
    if (string[0] == '\0') return *this;
    if (data_ == nullptr){
        data_ = new char[strlen(string) + 1];
        strcpy(data_, string);
        size_ = strlen(string);
        return *this;
    }

    char* datacpy = new char[size_+strlen(string)+1];
    strcpy(datacpy, data_);

    for (auto i = 0u; i < strlen(string); i++){
        datacpy[i+size_] = string[i];
    }
    datacpy[size_+strlen(string)] = '\0';

    delete[] data_;
    data_= datacpy;

    size_ = strlen(data_);

    return *this;
}

String& String::append(const String& string) {
    if (string.data_ == nullptr) return *this;
    if (data_ == nullptr){
        data_ = new char[string.size_ + 1];
        strcpy(data_, string.data_);
        size_ = string.size_;
        return *this;
    }

    this->append(string.data_);

    return *this;
}

char& String::back() {
    return data_[size_-1];
}

char& String::front() {
    return data_[0];
}

char* String::data() {
    return data_;
}

void String::clear(){
    delete[] data_;
    data_ = nullptr;
    size_ = 0u;
}

unsigned String::size() const {
    return size_;
}

/*
unsigned String::capacity() const {
    return capacity_;
}
*/

String& String::insert(const unsigned int& index, const char & src) {
    if (index > size_){
        throw std::out_of_range("");
    }
    if (data_ == nullptr){
        data_ = new char[2];
        data_[0] = src;
        data_[1] = '\0';
        size_ = 1;

        return *this;
    }
    char* data_cpy = new char[size_ + 2];

    if (index == size_){
        strcpy(data_cpy, data_);
        data_cpy[index] = src;
    }
    else {
        auto i = 0u;
        auto j = 0u;
        while (j < size_) {
            if (i != index) {
                data_cpy[i] = data_[j];
                i += 1;
                j += 1;
            } else {
                data_cpy[i] = src;
                i += 1;
            }

        }

    }
    data_cpy[size_+1] = '\0';
    delete[] data_;
    data_ = data_cpy;
    size_ += 1;

    return *this;

}

String& String::insert(const unsigned int& index, const unsigned int& count, const char& src) {
    if (index > size_){
        throw std::out_of_range("");
    }
    if (data_ == nullptr){
        data_ = new char[count + 1];
        for(auto i = 0u; i < count; i++){
            data_[i] = src;
        }
        data_[count] = '\0';
        size_ = count;
        return *this;
    }

    char* data_cpy = new char[size_+count+1];


    if (index == size_){
        strcpy(data_cpy, data_);
        for(unsigned i = size_; i < index+count; i++){
            data_cpy[i] = src;
        }
    } else{
        auto i = 0u;
        auto j = 0u;
        while(j < size_){
            if (i >= index && i < index+count){
                data_cpy[i] = src;
                ++i;
            } else{
                data_cpy[i] = data_[j];
                ++i;
                ++j;
            }
        }
    }
    data_cpy[size_ + count] = '\0';
    delete[] data_;
    data_ = data_cpy;
    size_ += count;

    return *this;
}

std::ostream& operator<<(std::ostream& cout, const String& string){
    return cout << string.data_;
}