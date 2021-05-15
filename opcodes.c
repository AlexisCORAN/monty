#include "monty.h"

/**
* pall - prints the data of all nodes in stack
*@stack: pointer to the head node pointer of stack
*
*@line_number: the line number
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)(line_number);

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		if (temp == *stack)
		{
			return;
		}
	}
}

/**
* check_for_digit - checks that a string only contains digits
*
*@arg: string to check
*
* Return: 0 if only digits, else 1
*/

int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
* push - push an integer onto the stack
*
*@stack: double pointer to the beginning of the stack
*
*@line_number: script line number
*/

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
