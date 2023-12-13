#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - program executes ls -l /tmp in
 * five different child processes
 *
 * Return: 0
 */
int main(void)
{
	pid_t parent;
	pid_t child1;
	pid_t child2;
	pid_t child3;
	pid_t child4;
	pid_t child5;
	int *status;

	char *command[] = {"ls", "-l", "/tmp", NULL};

	child1 = fork();
	if (child1 == 0)
	{
		execve("/bin/tmp", command, NULL);
		waitpid(child1,&status, NULL);

		if (status < 0)
		{
			perror("Error");
			exit(-1);
		}
	}

	child2 = fork();
	if(child2 == 0)
	{
		execve("/bin/tmp", command, NULL);
		waitpid(child2, &status, NULL);
		if (status < 0)
                {
			perror("Error");
			exit(-1);
		}
	}


	child3 = fork();
	if(child3 == 0)
	{
		execve("/bin/tmp", command, NULL);
		waitpid(child3, &status, NULL);
		if (status < 0)
		{
			perror("Error");
			exit(-1);
		}
	}


	child4 = fork();
	if (child4 == 0)
	{
		execve("/bin/tmp", command, NULL);
		waitpid(child4, &status, NULL);
		if (status< 0)
		{
			perror("Error");
			exit(-1);
		}
	}

	child5 = fork();
	if (child5 == 0)
	{
		execve("/bin/tmp", command, NULL);
		waitpid(child5, &status, NULL);

		if (status < 0)
		{
			perror("Error");
			exit(-1);
		}
	}

	return (0);
}
