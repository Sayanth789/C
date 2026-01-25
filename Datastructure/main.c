#include <stdio.h>
#include "bitmap.h"

int main(void)
{
    size_t nbits = 16;
    bitnode *bm = create_bitmap(nbits);

    set_bit(bm, 0);
    set_bit(bm, 3);
    set_bit(bm, 7);
    set_bit(bm, 15);

    for (size_t i = 0; i < nbits; i++) {
        printf("bit %zu = %d\n", i, get_bit(bm, i));
    }

    clear_bit(bm, 3);
    printf("\nAfter clearing bit 3:\n");
    printf("bit 3 = %d\n", get_bit(bm, 3));

    destroy_bitmap(bm);
    return 0;
}
