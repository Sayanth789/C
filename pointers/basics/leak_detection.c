#include <stdlib.h>

int main() {
    int *p = malloc(100* sizeof(int));

    p = NULL;

    return 0;
    /* this can be fixed as 
    free(p);
    p = NULL;
    */
}