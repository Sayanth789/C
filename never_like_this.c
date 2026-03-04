#include <iostream>
#include <cassert>

void foo(int x, int y) {
    int t = 0;

    if (x > y) {
        t = x;
    } else {
        t = y;
    }

    if (t > x) {
        assert(false);
    }
}
