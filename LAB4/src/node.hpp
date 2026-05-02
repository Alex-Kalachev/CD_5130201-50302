#pragma once
#include "circle.hpp"
#include <iostream>

class List;

class Node{
    friend class List;


    private:
        Node* pPrev; //указатель на предыдущий элемент
        Node* pNext; //указатель на следующий элемент
        Circle m_Data;

    public:

        Node(){
            pPrev = nullptr;
            pNext = nullptr;
        }

        Node(Node* prev, Node* next, const Circle* pc):m_Data(*pc){
            this->pPrev = prev;
            this->pNext = next;
            prev->pNext = this;
            next->pPrev = this;
        }

        ~Node(){
            if (pPrev) pPrev->pNext = this->pNext;
            if (pNext) pNext->pPrev = this->pPrev;
        }


        friend std::ostream& operator<<(std::ostream& out, const List& other);


};