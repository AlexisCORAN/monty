#include "monty.h"

/**
* pint - print value on top of `stack', or exit if stack is empty
*
*@stack: double pointer to head of stack
*
*@line_number: line number of current operation
*/

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
* pop - pop top element
*
*@stack: double pointer to head of stack
*
*@line_number: line number of current operation
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;

	if (var.stack_len == 0)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	var.stack_len--;
}

/**
* swap - swap top two elements
*
*@stack: double pointer to head of stack
*
*@line_number: line number of current operation
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (var.stack_len < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}

/**
* add - add the top two elements of the stack
*
*@stack: double pointer tot he beginning of the stack
*
*@line_number: script line number
*/

void add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += n;
}


/**
* sub - subtract top element of stack from next element and push result
*
*@stack: double pointer to head of stack
*
*@line_number: line number of current operation
*/

void sub(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= n;
}
