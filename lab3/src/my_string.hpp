#pragma once
#include <cstring>
#include <iostream>
class MyString{

    private:
        char* m_data;
        int m_length;

    public:

    MyString(): m_length(0), m_data(nullptr) {}

    MyString(const char * str){

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

    MyString(const MyString &other){

        if (other.m_data == nullptr) {
            m_data = nullptr;
            m_length = 0;
            return;
        }

        m_length = other.m_length;
        m_data = new char[m_length+1];
        for (int i = 0; i<m_length; i++){
            m_data[i] = other.m_data[i];
        }
        m_data[m_length] = '\0';
    }

    ~MyString(){
        delete[] m_data;
    }

    MyString(MyString&& other) noexcept{

    m_data = other.m_data;
    m_length = other.m_length;

    other.m_data = nullptr;
    other.m_length = 0;

    }

    MyString& operator= (const MyString& other){

        if (this == &other){
            return *this;
        }

        if (other.m_data == nullptr) {
            delete[] m_data;
            m_data = nullptr;
            m_length = 0;
            return *this;
        }

        delete[] m_data;

        m_length = other.m_length;

        m_data = new char[m_length+1];

        for (int i = 0; i<m_length; i++){
            m_data[i] = other.m_data[i];
        }
        m_data[m_length] = '\0';

        return *this;
    }
    
    MyString& operator+=(const MyString& other) {
        if (other.m_data == nullptr) {
            return *this;
        }

        int old_length = m_length;
        int new_length = m_length + other.m_length;

        char* new_data = new char[new_length + 1];

        
        for (int i = 0; i < old_length; i++) {
            new_data[i] = m_data[i];
        }

    
        for (int i = 0; i < other.m_length; i++) {
            new_data[old_length + i] = other.m_data[i];
        }

        new_data[new_length] = '\0';

        delete[] m_data;
        m_data = new_data;
        m_length = new_length;

        return *this;
    }
    
    MyString& operator+=(const char* str) {
        if (str == nullptr) {
            return *this;
        }

        int old_length = m_length;
        int add_length = strlen(str);
        int new_length = old_length + add_length;

        char* new_data = new char[new_length + 1];

        // копируем старую строку
        for (int i = 0; i < old_length; i++) {
            new_data[i] = m_data[i];
        }

        // дописываем новую
        for (int i = 0; i < add_length; i++) {
            new_data[old_length + i] = str[i];
        }

        new_data[new_length] = '\0';

        delete[] m_data;
        m_data = new_data;
        m_length = new_length;

        return *this;
    }

    MyString operator+(const MyString& other) const{

        MyString res = *this;
        res += other;
        return res;

    }

    MyString operator+(const char* str) const{

        MyString res = *this;
        res += str;
        return res;
    }
    
    bool operator==(const MyString& other) const{
        return std::strcmp(m_data, other.m_data) == 0;
    }

    bool operator!=(const MyString& other) const{
        return std::strcmp(m_data, other.m_data) != 0;
    }

    bool operator<(const MyString& other) const{
        return std::strcmp(m_data, other.m_data) < 0;
    }

    bool operator<=(const MyString& other) const{
        return std::strcmp(m_data, other.m_data) <= 0;
    }

    bool operator==(const char* str) const{
        return std::strcmp(m_data, str) == 0;
    }

    bool operator!=(const char* str) const{
        return std::strcmp(m_data, str) != 0;
    }

    bool operator<(const char* str) const{
        return std::strcmp(m_data, str) < 0;
    }

    bool operator<=(const char* str) const{
        return std::strcmp(m_data, str) <= 0;
    }

    MyString& operator=(MyString&& other){

        if (this == &other ){
            return *this;
        }
        delete[] m_data;
        m_data = other.m_data;
        other.m_data = nullptr;
        m_length = other.m_length;
        other.m_length = 0;
        return *this;

    }

    char& operator[] (size_t i){
        if (i >= m_length){
            throw std::out_of_range("Index out of range");
        }

        return m_data[i];
    }

    const char& operator[](size_t i) const {
    if (i >= m_length) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[i];
}

    friend MyString operator+(const char* str, const MyString& other);

    friend bool operator==(const char* str, const MyString& other);

    friend bool operator!=(const char* str, const MyString& other);

    friend bool operator<(const char* str, const MyString& other);

    friend bool operator<=(const char* str, const MyString& other);

    friend std::ostream& operator << (std::ostream& out, const MyString& other);

    friend std::istream& operator >> (std::istream& in, MyString& other);

    char get(int i) const;
    void set(int i, char c);
    void set_new_string(const char *str);
    void print() const;
    void read_line();
    const char* get_data() const;
    int get_length() const{
        return m_length;
    }

};

inline MyString addTxtExtension(const MyString &path) { return path + ".txt"; }
