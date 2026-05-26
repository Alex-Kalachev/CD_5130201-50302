#include <iostream>
#include <cassert>
#include "../src/rect.hpp"

int main(){

    Rect r_test(0, 10, 20, 0);

    assert(r_test.get_width() == 10);
    assert(r_test.get_height() == 20);
    assert(r_test.get_square() == 200);

    r_test.set_width(50); 
    assert(r_test.get_left() == 0);   
    assert(r_test.get_right() == 50); 
    assert(r_test.get_width() == 50);

    r_test.set_height(30);
    assert(r_test.get_bottom() == 0); 
    assert(r_test.get_top() == 30);
    assert(r_test.get_height() == 30);

    std::cout << "test_rect_properties passed!\n";

    return 0;
}