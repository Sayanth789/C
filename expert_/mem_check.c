/*
How much memory can we allocate?

This program help see how much memory we can allocate in the process

*/

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int Mb = 0;
//     while (malloc(1 << 20)) ++Mb;
//     printf("Allocated %d Mb total \n", Mb);
// }

/*
Cache Memories are made of this:

Line :> A line is the unit of access to a cache. Each line has has 2 parts a data 
section and a tag specifying the address that it represents 

Block : he data content of a line is referred to as a block. A block holds the bytes moved between a
line and main memory. A typical block size is 32 bytes.

The contents of a cache line represent a particular block of memory, and it will respond if a
processor tries to access that address range. The cache line "pretends" to be that address range
in memory, only considerably faster.

Cache : A cache consists of a big (typically 64 Kbytes to 1 Mbyte or more) collection of lines.
Sometimes associative memory hardware is used to speed up access to the tags. Cache is
located next to the CPU for speed, and the memory system and bus are highly tuned to
optimize the movement of cache-block-sized chunks of data.


*/

/*
Run the following program to see if you can detect cache effects on your system.
*/

#include <stdio.h>
#include <string.h> // Required for memcpy
#include <time.h>   // Required to measure execution time

// Fixed typos in the macros
#define DUMBCOPY for (i = 0; i < 65536; i++) destination[i] = source[i]
#define SMARTCOPY memcpy(destination, source, 65536)

int main() {
    char source[65536], destination[65536];
    int i, j;
    clock_t start, end;

    // Initialize source array with dummy data so it's not empty
    memset(source, 'A', 65536);

    // --- Test 1: DUMBCOPY ---
    start = clock();
    for (j = 0; j < 10000; j++) {
        DUMBCOPY;
    }
    // Read an element so the compiler doesn't optimize away the loop
    printf("Dumbcopy dummy read: %c\n", destination[0]);
    end = clock();
    printf("DUMBCOPY time: %f seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);


    // --- Test 2: SMARTCOPY ---
    start = clock();
    for (j = 0; j < 10000; j++) {
        SMARTCOPY;
    }
    // Read an element so the compiler doesn't optimize away the loop
    printf("Smartcopy dummy read: %c\n", destination[0]);
    end = clock();
    printf("SMARTCOPY time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}


