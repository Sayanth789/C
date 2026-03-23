/* 
Instructions normally execute sequentially, but control flow
statements (if, loops, function calls, goto) cause the program
to jump to different locations in memory.

*/


#include <stdio.h>

int Add(int a, int b) {
    return a + b;

} 


int main() {
    int c;
    int (*p)(int, int);

    // p = &Add;
    // c = (*p)(2, 3);
    p = Add;
    c = p(2, 3);
    printf("%d", c);


}