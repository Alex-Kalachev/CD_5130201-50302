#include <iostream>
#include "../src/rect.hpp"
#include <cassert>

int main(){

    Rect r_tect_operations(0, 10, 20, 0);

    r_tect_operations.inflate(10);

    assert(r_tect_operations.get_left() == -10);
    assert(r_tect_operations.get_right() == 20);
    assert(r_tect_operations.get_top() == 30);
    assert(r_tect_operations.get_bottom() == -10);
    assert(r_tect_operations.get_width() == 30);
    assert(r_tect_operations.get_height() == 40);

    r_tect_operations.inflate(3, 5);

    assert(r_tect_operations.get_left() == -13);
    assert(r_tect_operations.get_right() == 23);
    assert(r_tect_operations.get_top() == 35);
    assert(r_tect_operations.get_bottom() == -15);
    assert(r_tect_operations.get_width() == 36);
    assert(r_tect_operations.get_height() == 50);

    r_tect_operations.inflate(2,2,5,5);

    assert(r_tect_operations.get_left() == -15);
    assert(r_tect_operations.get_right() == 25);
    assert(r_tect_operations.get_top() == 40);
    assert(r_tect_operations.get_bottom() == -20);
    assert(r_tect_operations.get_width() == 40);
    assert(r_tect_operations.get_height() == 60);

    r_tect_operations.move(5,5);

    assert(r_tect_operations.get_left() == -10);
    assert(r_tect_operations.get_right() == 30);
    assert(r_tect_operations.get_top() == 45);
    assert(r_tect_operations.get_bottom() == -15);
    assert(r_tect_operations.get_width() == 40);
    assert(r_tect_operations.get_height() == 60);

    r_tect_operations.move(5);

    assert(r_tect_operations.get_left() == -5);
    assert(r_tect_operations.get_right() == 35);
    assert(r_tect_operations.get_top() == 45);
    assert(r_tect_operations.get_bottom() == -15);
    assert(r_tect_operations.get_width() == 40);
    assert(r_tect_operations.get_height() == 60);

    std::cout << "test_rect_operations passed!\n";
    
    return 0;
}