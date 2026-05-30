// pointer is another data type so a fn: can return it

#include <stdio.h>
#include <stdlib.h>

/*


int Add(int a, int b) {

    int c = a+b;
    return c;

}


int main() {
    int x = 2 , y = 4;
    // here the value in a of main is copied to a of add
    // and the same is true for b, i.e: they aren't same.


    int z = Add(x,  y);
    printf("Sum = %d\n", z);
}


*/

// so we use the call by ref

void PrintHelloWorld(){
    printf("hello world\n");

}

int *Add(int *a, int *b) {
    printf("Address of a in Add = %d\n", &a);

    printf("Adress of a in Add = %d\n", &a);
    printf("Value in a of Add (addres of a of main) = %d\n", a);
    printf("Value at address stored in a of Add = %d\n", *a);

    int c = (*a) + (*b);

    return c;
}


int main() {

    int a = 2, b = 4;
    printf("Address of a in main = %d\n", &a);

    int* ptr = Add(&a, &b);

    // Call by reference 
    int c = Add(&a, &b); // a and b are integers local to Main.
    printf("Sum = %d\n", c);
    printf("Sum = %d\n", *ptr);


}