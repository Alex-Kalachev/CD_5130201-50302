#pragma once
#include "my_string.hpp"

class WorkerData
{
    public:
        MyString m_name ;
        int m_age;
        double m_work_experience;
        double m_salary;
    
    public:
        WorkerData() : m_name(""), m_age(0), m_work_experience(0), m_salary(0) {}

        WorkerData(const MyString& name, int age, double work_experience, double salary) : m_name(name), m_age(age), m_work_experience(work_experience), m_salary(salary) {}

};

struct Worker_bs
{
    MyString surname;
    WorkerData data;
};

class WorkerDb
{
    private:

        Worker_bs* m_data;
        size_t m_size; // число заполненных столбцов
        size_t m_capacity; // число столбцов всего
        
    public:

    size_t get_m_size() const{
        return m_size;
    }

    class Iterator
    {
        private:
            Worker_bs* ptr;  // указатель на текущий элемент

        public:
            Iterator(Worker_bs* p) : ptr(p) {}

            
            WorkerData& operator*()
            {
                return ptr->data;
            }

            WorkerData* operator->()
            {
                return &(ptr->data);
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

            
            MyString key() const
            {
                return ptr->surname;
            }

            friend std::ostream& operator << (std::ostream& out, WorkerDb::Iterator db);

};

        WorkerDb()
        {
            m_size = 0;
            m_capacity = 10;
            m_data = new Worker_bs[m_capacity];
        }

        ~WorkerDb()
        {
            delete[] m_data;
        }
        
        // TO_DO: сделать эффективнее


        size_t hash(const MyString& str) const {
            size_t h = 0;
            for (int i = 0; i < str.get_length(); i++) {
                h = h * 33 + str[i];
            }
            return h;
        }

        void resize() {
            size_t old_capacity = m_capacity;
            Worker_bs* old_data = m_data;

            m_capacity *= 2;
            m_data = new Worker_bs[m_capacity]; 
            m_size = 0; 

            for (size_t i = 0; i < old_capacity; ++i) {

                if (old_data[i].surname != MyString("")) {

                    (*this)[old_data[i].surname] = old_data[i].data; 
                }
            }
            delete[] old_data;
        }

        WorkerData& operator[](const MyString& str_surname) {
            
            if (m_size >= m_capacity * 0.8) {
                resize();
            }

            size_t i = hash(str_surname) % m_capacity;

            while (true) {

                if (m_data[i].surname == str_surname) {
                    return m_data[i].data;
                }

                if (m_data[i].surname == MyString("")) {
                    m_data[i].surname = str_surname;
                    m_data[i].data = WorkerData(); 
                    m_size++;
                    return m_data[i].data;
                }

                i = (i + 1) % m_capacity;
            }
        } // Сложность алгоритма O(1) (стремится к этому)


        Iterator begin()
        {
            return Iterator(m_data);
        }

        Iterator end()
        {
            return Iterator(m_data + m_size);
        }


};

void print_db(WorkerDb&);
double get_avg_age(WorkerDb&);