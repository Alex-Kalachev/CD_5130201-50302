#pragma once
#include "node.hpp"
#include <iostream>

class List{

    private:
        Node Head; // фиктивный элемент, который является признаком начала списка
        Node Tail; // фиктивный элемент, который является признаком конца списка
	    size_t m_size;	//количество элементов

    public:


        List() :m_size(0) {
            Head.pNext = &Tail;
            Tail.pPrev = &Head;
            Head.pPrev = nullptr;
            Tail.pNext = nullptr;
        }

        void add_first(const Circle& circle){
            Node* prev = &Head;
            Node* next = Head.pNext;
            new Node(prev, next, &circle);
            m_size += 1;
        }

        void add_end(const Circle& circle){
            Node* next = &Tail;
            Node* prev = Tail.pPrev;
            new Node(prev, next, &circle);
            m_size += 1;
        }

        bool delete_one_element(const Circle& circle){
            Node* element  = this->Head.pNext;
            for (; (element != &Tail);) {
                if (element->m_Data == circle){
                    delete element;
                    m_size--;
                    return true;
                }
                element = element->pNext;
            }

            return false;
        }

        size_t delete_all_elements(const Circle& circle){
            Node* element  = this->Head.pNext;
            size_t i = 0;
            for (; (element != &Tail);) {
                if (element->m_Data == circle){
                    Node* buf_element = element->pNext;
                    delete element;
                    m_size--;
                    i++;
                    element = buf_element;
                }
                else{
                    element = element->pNext;
                }
            }

            return i;
        }

        void clear(){
            Node* element  = this->Head.pNext;
            for (; (element != &Tail);) {
                Node* buf_element = element->pNext;
                delete element;
                element = buf_element;
            }

            m_size = 0;
        }

        bool empty() const {
            return (this->Head.pNext == &Tail);
        }

        size_t size() const {
            return m_size;
        }

        Node* find(const Circle& circle){
            Node* element  = this->Head.pNext;
            for (; (element != &Tail);) {
                if (element->m_Data == circle){
                    return element;
                }
                element = element->pNext;
            }

            return nullptr;
        }

        void upsort(){
            bool swapped = false;
            for (size_t i = 0; i < m_size; i++){
                swapped = false;
                Node* current  = this->Head.pNext;
                for (; (current->pNext != &Tail);) {
                    Node* next = current->pNext;
                    if (current->m_Data.get_radius() > next->m_Data.get_radius()){
                        Circle buf_circle = current->m_Data;
                        current->m_Data = next->m_Data;
                        next->m_Data = buf_circle;
                        swapped = true;
                    }

                    current = current->pNext;

                }

                if (swapped == 0){
                    break;
                }
            }
        }

        friend std::ostream& operator << (std::ostream& out, const List& other);
        Circle get(size_t index) const;


};

