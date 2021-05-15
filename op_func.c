#include "monty.h"

/**
* get_op_func - check valid opcodes
*
*@op: op to check.
*
*@stack: double pointer to the beginnig of the stack.
*
*@line_number: line number.
*/

void get_op_func(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, op)  == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}

	dprintf(2, "L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
