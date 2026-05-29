#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>     // Required for system()
#include <sys/ioctl.h>  // Fixed header for FIONREAD on Linux
#include <curses.h>

int kbhit() {
    int i;
    // Fixed typo: changed 'itoctl' to 'ioctl'
    ioctl(0, FIONREAD, &i);
    return i;  // Returns a count of chars available to read
}
/*

int main() {            // Added explicit int return type
    int i = 0;
    int c = ' ';        // Fixed the missing space typo

    // Switch terminal to raw mode (don't wait for Enter key, don't echo characters)
    system("stty raw -echo");

    printf("Enter 'q' to quit \r\n");

    for (; c != 'q'; i++) {
        if (kbhit()) {
            c = getchar();
            // Added \r\n because raw terminal mode requires carriage return (\r)
            printf("\r\nGot %c on iteration %d\r\n", c, i);
        }
        
        // Add a tiny delay to keep the CPU from maxing out at 100% usage
        usleep(10000); 
    }

    // CRITICAL: Reset terminal back to normal (cooked) mode before exiting
    system("stty cooked echo");
    printf("\r\nTerminal restored. Goodbye!\n");

    return 0;
}

*/

// Rewritting for curses 
int main() {            // Added explicit int return type
    int i = 0;
    int c = ' ';        // Fixed the missing space typo

    // Switch terminal to raw mode (don't wait for Enter key, don't echo characters)
    system("stty raw -echo");

    printf("Enter 'q' to quit \r\n");

    for (; c != 'q'; i++) {
        if (kbhit()) {
            c = getchar();
            // Added \r\n because raw terminal mode requires carriage return (\r)
            printf("\r\nGot %c on iteration %d\r\n", c, i);
        }
        
        // Add a tiny delay to keep the CPU from maxing out at 100% usage
        usleep(10000); 
    }

    // CRITICAL: Reset terminal back to normal (cooked) mode before exiting
    system("stty cooked echo");
    printf("\r\nTerminal restored. Goodbye!\n");

    return 0;
}
