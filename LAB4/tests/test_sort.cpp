#include "list.hpp"
#include <cassert>

int main() {
    List l;

    l.add_end(Circle(0,0,5));
    l.add_end(Circle(0,0,2));
    l.add_end(Circle(0,0,7));

    l.upsort();

    assert(l.get(0).get_radius() == 2);
    assert(l.get(1).get_radius() == 5);
    assert(l.get(2).get_radius() == 7);

    return 0;
}