#include <iostream>
#include "barrel.hpp"

void Bochka::iteration (Bochka &other_bochka){
    double cup_volume = 1.0;

    double alcohol_one_litter = other_bochka.сoncentration()/100.0;

    other_bochka.m_all_volume -= cup_volume;
    other_bochka.m_alcohol_volume -= alcohol_one_litter;

    this->m_all_volume += cup_volume;
    this->m_alcohol_volume += alcohol_one_litter;

}
