#include <iostream>
#include <cassert>

// Bug: t = max(x, y). If y > x, the else branch sets t = y,
// making t > x true and triggering assert(false).
// Thus the else case always fails even though it is valid.


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
