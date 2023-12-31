#ifndef __MONTY_H__
#define __MONTY_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#endif /*_GNU_SOURCE*/
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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


extern int stackBusy;

/*NOTE: Stack Functions  */
stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/*NOTE: Helper functions*/
int isNumber(char *str);
void exitError(stack_t **stack);

/*NOTE: Monty functions for I/O*/

typedef void (*instructionTable)(stack_t **stack, unsigned int line_number);
void readFileByteCode(char *filename, stack_t **stack);
char *parseLine(char *line);
instructionTable getOpcodeFunc(char *str);

/*NOTE: Monty instruction table*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);

/*NOTE: Math functions for Monty*/
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
#endif /*__MONTY_H__*/
