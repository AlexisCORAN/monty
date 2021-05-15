#include "monty.h"

var_t var;

/**
* main - Monty bytecode interpreter
* @argc: number of arguments passed
* @argv: array of argument strings
*
* Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
*/

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file = NULL;
	unsigned int line_number = 0;
	char *lineptr = NULL;
	char *op = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_lineptr, &lineptr);
	on_exit(free_stack, &stack);
	on_exit(close_file, file);
	while (getline(&lineptr, &n, file) != -1)
	{
		line_number++;
		op = strtok(lineptr, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			get_op_func(op, &stack, line_number);
		}
	}
	 exit(EXIT_SUCCESS);
}
