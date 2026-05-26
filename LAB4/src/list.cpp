#include "list.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const List& other){
    Node* element = other.Head.pNext;
    size_t i = 1;

    while (element != &other.Tail) {
        out << "Элемент списка " << i << ": радиус " << element->m_Data.get_radius()
            << ", координаты центра "
            << element->m_Data.get_center().get_x() << " "
            << element->m_Data.get_center().get_y() << "\n";

        element = element->pNext;
        i++;
    }

    return out;
}


Circle List::get(size_t index) const {
    Node* current = Head.pNext;
    size_t i = 0;

    while (current != &Tail) {
        if (i == index)
            return current->m_Data;

        current = current->pNext;
        i++;
    }

    throw std::out_of_range("Index out of range");
}