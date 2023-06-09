#include "shell.h"

/**
 * main - Entry point for the shell program.
 * Return: Always 0.
 */

int main(void)
{
	char line[BUFFER_SIZE];

	exit_status = 0;

	while (1)
	{
		prompt();
		if (fgets(line, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		execute_command(line);
	}

	return (0);
}
