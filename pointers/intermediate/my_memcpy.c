#include <stdio.h>
#include <stddef.h>

void* my_memory(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;  // as source memory shouldn't modified.

    // Check for overlap: dest is inside the src block
    if (d > s && d < s + n) {
        // copy backwards from the end to prevent overwriting src data 
        for (size_t i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }
    else {

        // Normal forward copy 
        for (size_t i=0; i <n; i++) {
            *d = *s;
            d++;
            s++;
        }
    }
    return dest;
} 

verything is byte-level (char *)
memcpy = raw memory copy