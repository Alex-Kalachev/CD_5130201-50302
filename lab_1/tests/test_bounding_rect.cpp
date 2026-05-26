#include <iostream>
#include "../src/rect.hpp"
#include <cassert>

int main(){

    // Проверка 1. прямойгольники пересекаются
    Rect r1_test_bounding(0, 10, 10, 0);
    Rect r2_test_bounding(5, 15, 15, 5);

    Rect res1 = bounding_rect(r1_test_bounding, r2_test_bounding);

    assert(res1.get_left() == 0);
    assert(res1.get_right() == 15);
    assert(res1.get_top() == 15);
    assert(res1.get_bottom() == 0);


    // Проверка 2. один из прямойгольников вложен в другой

    Rect r_big(0, 100, 100, 0);
    Rect r_small(20, 30, 30, 20);

    Rect res2 = bounding_rect(r_big, r_small);

    assert(res2.get_left() == 0);
    assert(res2.get_right() == 100);
    assert(res2.get_top() == 100);
    assert(res2.get_bottom() == 0);

    // Проверка 3. введены некоректно координаты

    Rect r_inverted(50, 10, 0, 40);
    Rect r_simple(5, 0, 0, 5);
    
    Rect res3 = bounding_rect(r_inverted, r_simple);
    
    assert(res3.get_left() == 0);
    assert(res3.get_right() == 50);
    assert(res3.get_top() == 40);
    assert(res3.get_bottom() == 0);

    std::cout << "test_bounding_rect passed!\n";

    return 0;
}