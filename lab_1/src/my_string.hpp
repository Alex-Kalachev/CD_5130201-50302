#pragma once
#include <cstring>
class MyString{

    private:
        char* m_data;
        int m_length;

    public:

    MyString(): m_length(0), m_data(nullptr)
    {
        // TODO: сделать инициализацию без выделения памяти
        // TODO: узнать, как инициализировать поля, с помощью их конструкторов, использовать это
    }

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

    char get(int i) const;
    void set(int i, char c);
    void set_new_string(const char *str);
    void print() const;
    void read_line();
    const char* get_data() const ;

};