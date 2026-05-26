#include <iostream>
#include "../src/rect.hpp"
#include <cassert>

int main(){

    Rect r_default; // создаем объект, поля которого конструктор инициализирует 0

    assert(r_default.get_left() == 0);
    assert(r_default.get_right() == 0);
    assert(r_default.get_top() == 0);
    assert(r_default.get_bottom() == 0);

    Rect r_with_parameters(10, 40 , 100, 50); // создаем объект, для которого вызываем конструтор с параметрами

    assert(r_with_parameters.get_left() == 10);
    assert(r_with_parameters.get_right() == 40);
    assert(r_with_parameters.get_top() == 100);
    assert(r_with_parameters.get_bottom() == 50);

    Rect r_copy = r_with_parameters;

    assert(r_copy.get_left() == 10);
    assert(r_copy.get_right() == 40);
    assert(r_copy.get_top() == 100);
    assert(r_copy.get_bottom() == 50);

    r_copy.set_all(1,2,4,3);

    assert(r_copy.get_left() == 1);
    assert(r_copy.get_right() == 2);
    assert(r_copy.get_top() == 4);
    assert(r_copy.get_bottom() == 3);

    std::cout << "test_rect_basic passed!\n";

    return 0;
}