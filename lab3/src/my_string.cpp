#include "my_string.hpp"
#include <stdexcept>
#include <cstring>
#include <iostream>


char MyString::get(int i) const{
    if (i < 0 || i >= m_length) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[i];
}

void MyString::set(int i, char c){
    if (i < 0 || i >= m_length) {
        throw std::out_of_range("Index out of bounds");
    }

    m_data[i] = c;
    
}

void MyString::set_new_string(const char *str){

    delete[] m_data;

    if (str == nullptr) {
        m_data = nullptr;
        m_length = 0;
        return;
    }

    m_length = strlen(str);
    m_data = new char[m_length + 1];
    for (int i = 0; i < m_length; i++){
        m_data[i] = str[i];
    }

    m_data[m_length] = '\0';
}

void MyString::print() const{

    std::cout << "Вывод строки: \t";
    
    if (m_data != nullptr) {
        for (int i = 0; i < m_length; i++){
            std::cout << m_data[i];
        }
    }

    std::cout << "\n";
}

void MyString::read_line(){

    std::cout << "Введите строку в терминал: \n";

    int capacity = 10; 
    int length = 0;
    char* buffer = new char[capacity];

    char c;

    while (std::cin.get(c) && c != '\n') {

        if (length + 1 >= capacity) {
            capacity *= 2; 
            char* new_buffer = new char[capacity];
            for (int i = 0; i < length; i++) {
                new_buffer[i] = buffer[i];
            }
            delete[] buffer;
            buffer = new_buffer;
        }
        buffer[length++] = c;
    }
    buffer[length] = '\0'; 

    
    delete[] m_data;
    m_data = new char[length + 1];
    m_length = length;
    for (int i = 0; i <= length; i++) {
        m_data[i] = buffer[i];
    }

    delete[] buffer;
}

const char* MyString::get_data() const {
    return (m_data != nullptr) ? m_data : "";
}

MyString operator+(const char* str, const MyString& other){
        
        MyString res(str);
        res += other;
        return std::move(res);

}

bool operator==(const char* str, const MyString& other){

    MyString res(str);
    return res == other;

}

bool operator!=(const char* str, const MyString& other){
   
    MyString res(str);
    return res != other;
   
}

bool operator<(const char* str, const MyString& other){

    MyString res(str);
    return res < other;

}

bool operator<=(const char* str, const MyString& other){
    
    MyString res(str);
    return res <= other;

}

std::ostream& operator << (std::ostream& out, const MyString& other){

    return out << other.m_data;

}

std::istream& operator>>(std::istream& in, MyString& other) {
    std::cout << "Enter your string: ";

    char ch;
    int capacity = 0;           
    int length = 0;
    char* buffer = new char[capacity];

    while (in.get(ch) && ch != '\n') {
        if (length + 1 >= capacity) {
            capacity += 1;

            char* new_buffer = new char[capacity];
            for (int i = 0; i < length; i++) {
                new_buffer[i] = buffer[i];
            }
            delete[] buffer;
            buffer = new_buffer;
        }

        buffer[length++] = ch;
    }

    buffer[length] = '\0';

    delete[] other.m_data;

    other.m_length = length;
    other.m_data = new char[other.m_length + 1];

    for (int i = 0; i <= other.m_length; i++) {
        other.m_data[i] = buffer[i];
    }

    delete[] buffer;

    return in;
}