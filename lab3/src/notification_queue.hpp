#pragma once

#include "notification_class.hpp"

class NotificationQueue

{
    private:
        Notification_Class** m_data;
        size_t m_size; 
        size_t m_capacity;

        size_t m_get; // забираем  
        size_t m_put; // вставляем  

    public:

        NotificationQueue() : m_size(0), m_capacity(10), m_get(0), m_put(0) {

            m_data = new Notification_Class*[m_capacity];

        }

        ~NotificationQueue(){
            for (size_t i = 0; i < m_size; i++) {
                delete m_data[i];   
            }
            delete[] m_data; 
        }

        void push(Notification_Class* sms){}

        size_t size() const{
            return m_size;
        }

        Notification_Class** get_data(){
            return m_data;
        }


        class Iterator{

        private:
            Notification_Class** ptr;  

        public:
            Iterator(Notification_Class** p) : ptr(p) {}

            Notification_Class* operator*()
            {
                return *ptr;
            }

            Notification_Class* operator->()
            {
                return *ptr;
            }

            
            Iterator& operator++()
            {
                ++ptr;
                return *this;
            }

            bool operator!=(const Iterator& other) const
            {
                return ptr != other.ptr;
            }

            bool operator==(const Iterator& other) const
            {
                return ptr == other.ptr;
            }
        };

        // Iterator begin()
        // {
        //     return Iterator(m_data);
        // }

        // Iterator end()
        // {
        //     return Iterator(m_data + m_size);
        // }

        Iterator begin() const
        {
            return Iterator(m_data);
        }

        Iterator end() const
        {
            return Iterator(m_data + m_size);
        }


        Notification_Class* pop();



};

class NotificationPriorityQueue
{
    private:
        Notification_Class** m_data;
        size_t m_size; 
        size_t m_capacity;
    public:

        NotificationPriorityQueue()  {
            m_size = 0;
            m_capacity = 10;
            m_data = new Notification_Class*[m_capacity];
        }
        ~NotificationPriorityQueue(){
            for (size_t i = 0; i < m_size; i++) {
                delete m_data[i];   
            }
            delete[] m_data; 
        }

        void push(Notification_Class* sms){
            if (sms == nullptr){
                return;
            }

            if (m_size == m_capacity){
                m_capacity*=2;
                Notification_Class** buffer = new Notification_Class*[m_capacity];

                for (size_t i = 0; i < m_size; i++){
                    buffer[i] = m_data[i];
                }

                delete[] m_data;
                m_data = buffer;

            }

            m_data[m_size] = sms;
            m_size++;
        }
        
        size_t size() const{
            return m_size;
        }

        class Iterator{

        private:
            Notification_Class** ptr;  

        public:
            Iterator(Notification_Class** p) : ptr(p) {}

            Notification_Class* operator*()
            {
                return *ptr;
            }

            Notification_Class* operator->()
            {
                return *ptr;
            }

            
            Iterator& operator++()
            {
                ++ptr;
                return *this;
            }

            bool operator!=(const Iterator& other) const
            {
                return ptr != other.ptr;
            }

            bool operator==(const Iterator& other) const
            {
                return ptr == other.ptr;
            }
        };

        Iterator begin()
        {
            return Iterator(m_data);
        }

        Iterator end()
        {
            return Iterator(m_data + m_size);
        }

        Iterator begin() const
        {
            return Iterator(m_data);
        }

        Iterator end() const
        {
            return Iterator(m_data + m_size);
        }


        Notification_Class* pop();



};

bool Time_min(Notification_Class* sms1, Notification_Class* sms2);
int TypePriority(Notification_Class* sms);
bool IsBetter(Notification_Class* a, Notification_Class* b);
