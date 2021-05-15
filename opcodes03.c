#include "monty.h"

/**
* op_div - divide second element of stack by top element
*
*@stack: double pointer to head of stack
*
*@line_number: line number of current operation
*/

void op_div(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	if (n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= n;
}

/**
* mul - multiply top two elements of stack and push result
*
*@stack: double pointer to head of stack
*
*@line_number: line number of current operation
*/

void mul(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= n;
}

/**
* mod - modulus of second element divided by top element
*
*@stack: double pointer to head of stack
*
*@line_number: line number of current operation
*/

void mod(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	if (n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= n;
}
