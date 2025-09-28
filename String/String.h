#pragma once
#include <iostream>
#include <cstring>
using namespace std;


class String{
public:
    String();
    explicit String(const char* str);
    String(const String& other);
    ~String();
    void set_string(const char* str);
    int count_words() const;
    const char* get_string() const;
    int find_substring(const char* substr);
    static int get_obj_count();
    char* to_string() const;


private:
    char* arr; //динамический массив
    size_t max_length; //максимальная длина оного
    size_t length; // длина строки в массиве


    static int count; //статическая контанта для подсчёта кол-ва объектов общая для всех объектов класса

};
