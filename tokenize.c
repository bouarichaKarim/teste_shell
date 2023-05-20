#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * parse_arguments - Tokenizes a string into arguments.
 * @line: The input string to be tokenized.
 *
 * Return: return an array of strings containing the arguments.
 */

char **parse_arguments(char *line)
{
	char **arguments;
	char *token;
	int arg_count = 0;

	/* Count the number of arguments */
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		arg_count++;
		token = strtok(NULL, " \t\n");
	}

	/* Allocate memory for arguments array */
	arguments = malloc((arg_count + 1) * sizeof(char *));
	if (arguments == NULL)
	{
		perror("Allocation error");
		return NULL;
	}

	/* Tokenize the command line into arguments */
	token = strtok(line, " \t\n");
	arg_count = 0;
	while (token != NULL)
	{
		arguments[arg_count] = strdup(token);
		if (arguments[arg_count] == NULL)
		{
			perror("Allocation error");
			free_arguments(arguments);
			return NULL;
		}
		arg_count++;
		token = strtok(NULL, " \t\n");
	}

	arguments[arg_count] = NULL;
	return arguments;
}

/**
 * free_arguments - Free the memory used by an array of arguments.
 * @arguments: Array of arguments.
 */
void free_arguments(char **arguments)
{
	if (arguments == NULL)
		return;

	for (int i = 0; arguments[i] != NULL; i++)
		free(arguments[i]);

	free(arguments);
}
