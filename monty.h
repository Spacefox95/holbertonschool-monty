#ifndef MONTY_CODE
#define MONTY_CODE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char *argv[]);
void exec(char *command, stack_t **stack);
void _free(stack_t **stack);
void (*op_function (char *command))(stack_t **stack, unsigned int line_number);
char *get_file_buffer(const char *filename);
void push(stack_t **stack, unsigned int line_number, char *buffer);
void pint_fct(stack_t **stack, unsigned int line_number);
void pop_fct(stack_t **stack, unsigned int line_number);
void swap_fct(stack_t **stack, unsigned int line_number);
void add_fct(stack_t **stack, unsigned int line_number);
void nop_fct(stack_t **stack, unsigned int line_number);
void pall_fct(stack_t **stack, unsigned int line_number);

#endif
