#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#define MAXLEN 1024
#define PROMPT "#cisfun$"
/**
 * main - sheel that runs commands withouts args
 *
 * Return: 0
 */
int main(void)
{
	int status;
	pid_t child;
	char command[MAXLEN];

	while(1)
	{
		printf(PROMPT);

		if(fgets(command, MAXLEN, stdin) == NULL)
		{
			perror("Couldn't read from standard input");
			break;
		}
		
		if (command[strlen(command) - 1] == '\n')
		{
			command[strlen(command) - 1] = '\0';
		}
		
		if (strncmp(command,"^C", 2) == 0)
		{
			printf("Exiting CodyEmpress shell...\n");
			break;
		}
		
		child = fork();
		if(child == -1)
		{
			perror("Failed to create child process");
			continue;
		}
		else if (child == 0)
		{
			char *argv[] = {command, NULL};
			execve(command, argv, NULL);
			
			perror("Couldn't execute command in child process");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child, &status, 0);
		}
	}

	return (0);
}
