#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define PROMPT "#cisfun$ "

int main(void) {
    char cmd[MAX_CMD_LEN];
    pid_t pid;
    int status;

    while (1) {
        printf(PROMPT);  // Print the shell prompt
        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
            // Handle fgets error or EOF
            break;
        }

        // Remove trailing newline character
        cmd[strcspn(cmd, "\n")] = 0;

        // Exit the shell on "exit" command
        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        pid = fork();
        if (pid == -1) {
            // Handle fork error
            perror("fork");
            continue;
        }

        if (pid == 0) {
            // Child process
            char *argv[] = {cmd, NULL};  // Command with no arguments
            execve(cmd, argv, NULL);
            // If execve returns, it must have failed
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    printf("Exiting shell...\n");
    return 0;
}
