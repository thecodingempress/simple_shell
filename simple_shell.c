#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#define PROMPT "#cisfun$ "
/**
 * main - main shell file
 *
 * Return: 0
 */
int main(void)
{
	char command[MAXLEN];
	char *argv[] = {command, NULL};
	int status;
	pid_t pid;

	while (1)
	{
		printf(PROMPT);
		if (fgets(command, MAXLEN, stdin) == NULL)
		{
			perror("Failed to read from standard input");
			break;
		}
		command[strcspn(command, "\n")] = 0;
		if (strcmp(command, "^C") == 0)
			break;
		pid = fork();
		if (pid == -1)
		{
			perror("Failed to create child");
			continue;
		}
		else if (pid == 0)
		{
			execve(command, argv, environ);
			perror("Failed to execute command");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}
}
