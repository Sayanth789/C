// user defined type of named integer identifier helps 
// to make a program more readable

#include <stdio.h>

enum Day{Sun=1, Mon=2, Tue=3, Wed=4, Thu=5, Fri=6, Sat=7};

int main() {
    
    enum Day today = Tue;

   if (today == Sun || today == Sat) {
    printf("\nThis is the weekend! Party time!");

   }
   else {
    printf("\nI have work to do...!");
   } 


    return 0;
}