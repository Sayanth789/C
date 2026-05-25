/*Never make a file of the same name as of the 
existing func.
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>



// int main() {
//     while (1) {
//         printf("hello world\n");
//     }
//     return 0;
// }

// This is user defined sign
//  A signal handler can have any name, but it must return void and 
// accept a single int parameter, representing the signal number.


// void signalHandler(int sig) {
//     const char msg[] = "Caught SIGNIT\n";
//     write(STDOUT_FILENO, msg, sizeof(msg) - 1);
//     _exit(sig);
// }

// int main() {
//     signal(SIGINT, signalHandler);
//     while (1) {
//         printf("Hello world\n");
//         sleep(1);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>

// Signal handler function 
// void signalHandler(int sig) {
//     printf("Interrupt handled %d", sig);

//     // Optionally exit the program after handling.
// }

// int main() {
//     // Handle signal 

//     signal (SIGINT, signalHandler);

//     // Automatically generate a signal
//     raise(SIGINT);
//     return 0;
// }

/*
Write a signal handler to catch the INT 1B (Ctrl-Break) signal on a PC. Have it print a user-
friendly message, but not exit
*/


#include <stdio.h>
#include <signal.h> // Modern replacement for <dos.h> signal handling
#include <unistd.h> // Required for sleep()

// Our modern Linux signal handler function
void handle_ctrl_c(int sig) {
    printf("\n[Notice] Ctrl-C detected! Returning safely to the application loop...\n\n");
    // We do not call exit(), so the program continues running
}


int main() {
    printf("=== Linux SIGINT (Ctrl-C) Trap Initialized ===\n");
    printf("Press Ctrl-C to trigger the custom trap.\n");
    printf("To close the program entirely, press Ctrl-Z or close the terminal.\n\n");

    // Register our custom handler to intercept the SIGINT signal
    signal(SIGINT, handle_ctrl_c);

    // An infinite loop to keep the program open so you can test it
    while (1) {
        printf("Waiting for your action... (Sleeping for 3 seconds)\n");
        sleep(3); 
    }

    return 0;
}

