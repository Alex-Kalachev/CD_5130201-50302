#include "list.hpp"
#include <cassert>

int main() {
    List l;

    l.add_end(Circle(0,0,1));
    l.add_end(Circle(1,1,2));

    assert(l.size() == 2);

    return 0;
}