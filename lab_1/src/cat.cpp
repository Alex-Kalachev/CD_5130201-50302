#include "cat.hpp"
#include <cstring>

int SpeechBubble::find_next_len(int start_pos) {
    int text_end = m_input_len - start_pos;
    if (text_end <= m_max_width) return text_end;

    
    int last_space = -1;
    for (int j = 0; j <= m_max_width; j++) {
        if (m_input_text[start_pos + j] == ' ') {
            last_space = j;
        }
    }

    
    if (last_space > 0) {
        return last_space;
    } 
    
    // Если пробелов нет
    return m_max_width;
}

void SpeechBubble::add_line(const char* start, int len) {
    char* line = new char[len + 1];
    strncpy(line, start, len);
    line[len] = '\0';
    
    m_lines[m_line_count++] = line;
    if (len > m_actual_max_width) m_actual_max_width = len;
}

void SpeechBubble::run() {
    int pos = 0;
    while (pos < m_input_len) {

        while (pos < m_input_len && m_input_text[pos] == ' ') pos++;
        if (pos >= m_input_len) break;

        int len = find_next_len(pos);
        add_line(m_input_text + pos, len);
        pos += len;
    }
}

void SpeechBubble::print_border(bool top) {
    std::cout << " ";
    for (int i = 0; i < m_actual_max_width + 4; i++) {
        std::cout << (top ? "_" : "-");
    }
    std::cout << std::endl;
}

void SpeechBubble::render() {
    print_border(true);
    for (int i = 0; i < m_line_count; i++) {
        char start = '|', end = '|';
        if (m_line_count == 1) { start = '<'; end = '>'; }
        else if (i == 0) { start = '/'; end = '\\'; }
        else if (i == m_line_count - 1) { start = '\\'; end = '/'; }

        std::cout << start << "  " << m_lines[i];
        
        int pr = m_actual_max_width - strlen(m_lines[i]);
        for (int p = 0; p < pr; p++) std::cout << " ";
        
        std::cout << "  " << end << std::endl;
    }
    print_border(false);

    
    std::cout << "     \\\n      \\\n        /\\_/\\  (\n       ( ^.^ ) _)\n         \\\"/  (\n       ( | | )\n      (__d b__)" << std::endl;
}