#include <stdio.h>

int main() {
    int a = 1025;
    int *p;
    p = &a;

    printf("size of integer is %d bytes\n", sizeof(int));
    printf("address = %d, value = %d\n", p, *p);

    void *p0;
    p0 = p;
    printf("Adress = %d", p0);
 
    // printf("Adress = %d", p0+1); /* this will give compilation error*/.


}