#include "monty.h"

/**
* free_lineptr - free line pointer returned by getline
*
*@status: exit status
*
*@arg: pointer to line
*/

void free_lineptr(int status, void *arg)
{
	char **lineptr = arg;

	(void)status;
	if (*lineptr != NULL)
		free(*lineptr);
}

/**
* free_stack - frees the stack on exit
*@status: exit status
*@arg: double pointer to the stack
*/

void free_stack(int status, void *arg)
{
	stack_t **stack;
	stack_t *next;

	(void)status;

	stack = (stack_t **)arg;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.stack_len = 0;
}

/**
* close_file - close file stream
*
*@status: status passed to exit
*
*@arg: pointer to file stream
*/

void close_file(int status, void *arg)
{
	FILE *file;

	(void)status;

	file = (FILE *)arg;
	fclose(file);
}
