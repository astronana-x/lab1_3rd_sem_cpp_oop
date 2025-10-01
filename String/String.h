#pragma once
#include <iostream>
#include <cstring>
#include "Index/Index.h"

using namespace std;

class Index;

class String{
public:
//Лабораторная работа 1

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

    // Лабораторная работа 2
    static const size_t start_length;
    static const size_t resize_factor;
    static const size_t max_length_limit;
    static const char value_error;

    // Перегрузки операторов
    String operator+(const char* rhs) const;
    String operator+(const String& rhs) const;
    String operator-(const char* substr) const;
    String& operator=(const String& other);

    // Индексирование
    Index operator[](size_t indx);   // для записи
    char operator[](size_t indx) const; // для чтения

    // Методы для доступа к приватным полям из Index
    size_t get_length() const { return length; }
    size_t get_max_length() const { return max_length; }
    char* get_arr() { return arr; }
    void set_length(size_t new_length) { length = new_length; }

private:
    char* arr;           // динамический массив
    size_t max_length;   // текущий размер массива
    size_t length;       // фактическая длина строки

    static int count;    // количество объектов

    void _resize_array(size_t new_size); // увеличение размера массива
    friend class Index;
};
