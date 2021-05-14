#ifndef _MONTY_H_
#define _MONTY_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
* struct select_var - struct to contain the main variables
*			of the Monty interpreter
*
*@queue: flag to determine if in stack vs queue mode
*
*@stack_len: length of the stack
*/

typedef struct select_var
{
	int queue;
	size_t stack_len;
} var_t;

#define STACK 0
#define QUEUE 1

var_t var;
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
*@n: integer
*
*@prev: points to the previous element of the stack (or queue)
*
*@next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
*@opcode: the opcode
*
*@f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void get_op_func(char *op, stack_t **stack, unsigned int line_number);

/* Stack manipulation functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

void free_lineptr(int status, void *arg);
void free_stack(int status, void *arg);
void close_file(int status, void *arg);

stack_t *add_node(stack_t **stack, const int n);

#endif /* _MONTY_H_ */
