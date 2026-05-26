#include "worker_dd.hpp"
#include <iostream>

std::ostream& operator << (std::ostream& out, WorkerDb::Iterator it){
    return out << it->m_name << ", " << it->m_age << ", " << it->m_work_experience << ", " << it->m_salary;
}


void print_db(WorkerDb& db){
    std::cout << "База данных работников:\n";
        int i = 1;
        for (auto it = db.begin(); it != db.end(); ++it)
        {
            std::cout << "Номер " << i << " " << it.key() << ": " << it << "\n";
            
            i++;
        }
}

double get_avg_age(WorkerDb& db){

        double res = 0.;

        for (auto it = db.begin(); it != db.end(); ++it)
        {
            res += it->m_age;
        }

    return res/db.get_m_size();
}