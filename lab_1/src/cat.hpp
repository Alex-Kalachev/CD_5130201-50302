#pragma once
#include <iostream>

class SpeechBubble {
private:
    char* m_input_text;    //копия исходной строки   
    int m_input_len;    // длинна копии
    char** m_lines;     // разбитые строки
    int m_line_count;   // количество разбитых строк
    int m_max_width;    // макисмальная ширина разбитой строки - 40
    int m_actual_max_width;  // максимальная ширина получившаяся

    int find_next_len(int start_pos); 
    void add_line(const char* start, int len);
    void print_border(bool top);

public:
    SpeechBubble(const char* text, int width = 40){
        m_input_len = strlen(text);
        m_input_text = new char[m_input_len + 1];
        strcpy(m_input_text, text);

        m_max_width = width;
        m_line_count = 0;
        m_actual_max_width = 0;
        
        m_lines = new char*[m_input_len / 2 + 1];
}
    ~SpeechBubble() {
        delete[] m_input_text;
        
        for (int i = 0; i < m_line_count; i++) {
            delete[] m_lines[i];
        }
        delete[] m_lines;
}

    void run();   
    void render(); 
};

