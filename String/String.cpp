#include "String.h"


//определение статической константы:
int String :: count = 0;

//конструктор по умолчанию:
String :: String() {
    this->max_length = 10;
    this->length = 0;
    this->arr = new char[max_length];
    this->arr[0] = '\0'; 
    count++; 
}

//конструктор с параметром:
String :: String(const char* str){
    this->length = strlen(str);
    this->max_length = length + 1; 
    this->arr = new char[max_length];
    strcpy(arr, str);
    count++;
}

//конструктор копирования:
String :: String(const String& other){
    this->length = other.length;
    this->max_length = other.max_length;
    this->arr = new char[max_length];
    strcpy(arr, other.arr);
    count++;
}

//деструктор:
String :: ~String(){
    delete[] arr;
    count--;
}

//сеттер
void String :: set_string(const char* str){
    length = strlen(str);
    max_length = length + 1;
    delete[] arr;
    arr = new char[max_length];
    strcpy(arr, str);
}

//геттер
const char* String :: get_string() const{
    return arr;
}

//метод нахождения подстроки в строке:
int String::find_substring(const char* substr){
    char* pos = strstr(arr, substr);
    if (pos) return static_cast<int>(pos - arr); // явное приведение
    return -1;
}


//метод подсчёта количества слов в строке:
int String::count_words() const {
    if (length == 0) return 0;

    int count = 0;
    bool in_word = false;

    for (size_t i = 0; i < length; i++) {
        if (arr[i] != ' ' && arr[i] != '\t' && !in_word) {
            in_word = true;
            count++;
        }
        else if (arr[i] == ' ' || arr[i] == '\t') {
            in_word = false;
        }
    }
    return count;
}


//метод для получения количества объектов в классе:
int String :: get_obj_count(){
        return count;
    }

//метод для возвращения копии строки:
char* String::to_string() const {
    char* res = new char[length + 1]; 
    strcpy(res, arr);                 
    return res;                       
}
