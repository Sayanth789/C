#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_INPUT 1024
#define MAX_ARGS 100

// ------ PARSE INPUT ------------

void parseInput(char *input, char **args) {
    int i = 0;

    args[i] = strtok(input, " \n");

    // strtok - used to split string into smaller pieces, called tokens
    // based on specific delimiter chars.

    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \n");
    }
}

// ----------- Execute Command -----------------

void executeCommand(char **args) {
    pid_t pid = fork();
    
    if (pid < 0) {
        printf("Fork Failed\n");
        return;
    }

    if (pid == 0) {
        // Child Process 
        if (execvp(args[0], args) == -1) {
            printf("Command execution failed\n");
        }

        exit(1);
    } else {
        // parent process
        wait(NULL);
    }
}


int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("myshell> ");
        fflush(stdout);
        // fflsuh -> clear or flush the output buffer of a specific stream.

        if (fgets(input, MAX_INPUT, stdin) == NULL)
            continue;
        // remove newline handled by strtok
        
        // exit condition 
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        parseInput(input, args);

        if (args[0] != NULL) {
            executeCommand(args);
        }

    }

    printf("shell exited.\n");

    return 0;

}