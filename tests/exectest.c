#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Path to the executable. Replace this with the actual path.
    char *programPath = "/path/to/executable";

    // Arguments to the program. The first argument should be the program name.
    char *args[] = {programPath, "arg1", "arg2", NULL};

    // Using the current environment. 
    extern char **environ;

    // Execute the program. execve does not return on success.
    if (execve(programPath, args, environ) == -1) {
        // If execve returns, an error occurred.
        perror("Error executing execve");
        exit(EXIT_FAILURE);
    }

    // This part of the code is not reached if execve is successful.
    return 0;
}

