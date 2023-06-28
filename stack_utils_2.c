#include "monty.h"

/**
 * _nop - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Literally does nothing
 * Return: Nothing
 */
void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused))unsigned int line_number)
{
;
}

/**
 * _pchar - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Print the char at top of the stack
 * Return: Nothing
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
stack_t *stackList;
int value;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
exitError(stack);
}

stackList = *stack;
value = stackList->n;

if (!isprint(value))
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exitError(stack);
}

putchar(value);
putchar('\n');
}

/**
 * _pstr - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Print the starting string at top of the stack
 * Return: Nothing
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
stack_t *stackList;
int value;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
exitError(stack);
}

stackList = *stack;

while (stackList != NULL)
{
value = stackList->n;
if (value == 0)
	break;

if (!isprint(value))
	break;

putchar(value);
stackList = stackList->next;
}

putchar('\n');
}

/**
 * _stack - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Used to initiate a stack
 * Return: Nothing
 */
void _stack(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused))unsigned int line_number)
{
stackBusy = 0;
}

/**
 * _queue - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Used to initiate a queue
 * Return: Nothing
 */
void _queue(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused))unsigned int line_number)
{
stackBusy = 1;
}
