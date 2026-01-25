#include "bitmap.h"
#include <stdlib.h>
#include <limits.h>

bitnode *create_bitmap(size_t n)
{
    size_t num = (n + CHAR_BIT - 1) / CHAR_BIT;
    return calloc(num, sizeof(bitnode));
}

void destroy_bitmap(bitnode *bitmap)
{
    free(bitmap);
}

static inline bitnode _get_mask(size_t bitpos)
{
    return (bitnode)(1 << (7 - (bitpos % CHAR_BIT)));
}

void set_bit(bitnode *bitmap, size_t bitpos)
{
    if (!bitmap) return;

    size_t index = bitpos / CHAR_BIT;
    bitmap[index] |= _get_mask(bitpos);
}

void clear_bit(bitnode *bitmap, size_t bitpos)
{
    if (!bitmap) return;

    size_t index = bitpos / CHAR_BIT;
    bitmap[index] &= ~_get_mask(bitpos);
}

int get_bit(bitnode *bitmap, size_t bitpos)
{
    if (!bitmap) return 0;

    size_t index = bitpos / CHAR_BIT;
    return !!(bitmap[index] & _get_mask(bitpos));
}
