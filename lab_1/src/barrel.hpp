#pragma once

class Bochka{

    private:

    double m_all_volume;
    double m_alcohol_volume;

    public:

    double сoncentration() const{
        return m_alcohol_volume/m_all_volume * 100.0;
    }

    Bochka(double all_volume, double percent_alcohol_volume){
        m_all_volume = all_volume;
        m_alcohol_volume = all_volume * (percent_alcohol_volume/100.0);
    }

    void iteration (Bochka &other_bochka);
};