#pragma once
#include <iostream>
#include <cmath>

class Dop_functional{
    private:
        unsigned char* m_byte;

        unsigned char m_i;

    public:

        Dop_functional(unsigned char* byte, unsigned char i):m_byte(byte), m_i(i){}

        Dop_functional& operator=(bool value){
            if (value == 1){
                unsigned char mask = static_cast<unsigned char>(1u << m_i);
                *m_byte = *m_byte | mask;
            }
            else{
                unsigned char mask = static_cast<unsigned char>(1u << m_i);
                *m_byte = *m_byte & (~mask);
            }
            
            return *this;
        }

        Dop_functional& operator=(Dop_functional& other) {
            return *this = static_cast<bool>(other);
        }

        operator bool(){
            return ((*m_byte & (1u << m_i)) != 0);
        }

};



class BoolArray{
    private:
        unsigned char* m_data;
        size_t m_size;
        size_t m_capacity;
    
        public:
            BoolArray(size_t size, bool value = false) {
                m_size = size;
                m_capacity = m_size / 8 + ((m_size % 8) ? 1 : 0);

                m_data = new unsigned char[m_capacity];

                unsigned char v = value ? 255 : 0;
                for (size_t i = 0; i < m_capacity; i++) {
                    m_data[i] = v;
                }

                if (value && (m_size % 8 != 0)) {
                    m_data[m_capacity - 1] = (1 << m_size % 8) - 1;
                }
            }

            ~BoolArray(){
                delete[] m_data;
            }
            
            BoolArray(const BoolArray& other){
                m_size = other.m_size;
                m_capacity = other.m_capacity;
                m_data = new unsigned char[m_capacity];

                for (size_t i = 0; i < m_capacity; i++){
                    m_data[i] = other.m_data[i];
                }
            }

            BoolArray& operator=(const BoolArray& other) {
                if (this == &other) return *this;

                delete[] m_data;

                m_size = other.m_size;
                m_capacity = other.m_capacity;

                m_data = new unsigned char[m_capacity];

                for (size_t i = 0; i < m_capacity; ++i) {
                    m_data[i] = other.m_data[i];
                }

                return *this;
            }

            
            Dop_functional operator[](size_t index){
                if (index >= m_size) {
                    throw std::out_of_range("Index out of range");
                }
                size_t byte_index = index / 8 ;
                size_t bit_index  = index % 8;
                Dop_functional p(&m_data[byte_index], bit_index);
                
                return p;
            }

            size_t size() const { return m_size; }


            void resize(size_t size, bool value = false);


};