#include "monty.h"
#include <string.h>

/**
* _push - Entry Point
* @stack: stack to use
* @line_number: line number from file
* Description: Pushes arg from line number onto the stack
* Return: Nothing
*/
void _push(stack_t **stack, unsigned int line_number)
{
stack_t *newStackItem;
char *arg;
int push_arg = 0;

/*WARN: Unused newStackItem is causing leaks */
newStackItem = malloc(sizeof(stack_t));
if (newStackItem == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exitError(stack);
}

arg = strtok(NULL, "\n ");
if (isNumber(arg) == 1 && arg != NULL)
	push_arg = atoi(arg);

else
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exitError(stack);
}

if (stackBusy == 1)
	add_dnodeint_end(stack, push_arg);


if (stackBusy == 0)
	add_dnodeint(stack, push_arg);

/*NOTE: Free up the stack at the end*/
free(newStackItem);
}

/**
* _pall - Entry Point
* @stack: stack to use
* @line_number: line number from file
* Description: Pulls all the items from the stack
* Return: Nothing
*/
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
stack_t *stackList;

stackList = *stack;
while (stackList != NULL)
{
printf("%d\n", stackList->n);
stackList = stackList->next;
}
}


/**
* _pint - Entry Point
* @stack: stack to use
* @line_number: line number from file
* Description: Prints the top(first) item from the stack
* Return: Nothing
*/
void _pint(stack_t **stack, unsigned int line_number)
{
stack_t *stackList;

stackList = *stack;
if (stackList == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exitError(stack);
}
printf("%d\n", stackList->n);
}

/**
* _pop - Entry Point
* @stack: stack to use
* @line_number: line number from file
* Description: Delete top(first) item from the stack
* Return: Nothing
*/
void _pop(stack_t **stack, unsigned int line_number)
{
stack_t *tmpNode = NULL; /*Track the node*/
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exitError(stack);
}

/*NOTE: Pop the node */
tmpNode = (*stack);
(*stack) = (*stack)->next;
free(tmpNode);

if (*stack != NULL)
	(*stack)->prev = NULL;
}

/**
* _swap - Entry Point
* @stack: stack to use
* @line_number: line number from file
* Description: Swap the two top elements of the stack
* Return: Nothing
*/
void _swap(stack_t **stack, unsigned int line_number)
{
stack_t *stackList;
int tmp = 0;

stackList = *stack;
if (stackList == NULL || stackList->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exitError(stack);
}

tmp = stackList->n;
stackList->n = stackList->next->n;
stackList->next->n = tmp;
}
