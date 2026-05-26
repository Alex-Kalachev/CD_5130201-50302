#include "boolarray.hpp"

void BoolArray::resize(size_t size, bool value){
    if (size > m_size){
        BoolArray buf(size, value);

        for (int i = 0; i < m_size; i++) {
            buf[i] = (*this)[i];
        }

        *this = buf;

    }

    else{
        BoolArray buf(size);

        for (int i = 0; i < size; ++i) {
            buf[i] = (*this)[i];
        }

        *this = buf;

    }
}