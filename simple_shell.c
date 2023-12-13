#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define PROMPT "($) "
/**
 * main - main shell file
 * @argc: argument count
 * @argv: array of args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char command[MAXLEN];
	char *args[] = {command, NULL};
	int status;
	pid_t pid;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			printf(PROMPT);
		if (fgets(command, MAXLEN, stdin) == NULL)
		{
			if (feof(stdin))
			{
				if (is_interactive)
					printf("\n");
				break;
			}
			else
			{
				perror("Failed to read from standard input");
				continue;
			}
		}
		command[strcspn(command, "\n")] = 0;
		if (is_interactive && strcmp(command, "^C") == 0)
			break;
		pid = fork();
		if (pid == -1)
		{
			perror("Failed to create child");
			continue;
		}
		else if (pid == 0)
		{
			execve(command, args, environ);
			fprintf(stderr, "%s: %s: %s\n", args[0], command, strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);

		if (!is_interactive)
			break;
	}
	return (0);
}
