#include <stddef.h>
#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAXCHAR 1024
/**
 * main - displays the user's command
 *
 * Return: 0
 */
int main(void)
{
	char command[MAXCHAR];

	printf("$ ");
	fflush(stdout);

	fgets(command, MAXCHAR, stdin);
	fputs(command, stdout);

	return (0);
}
