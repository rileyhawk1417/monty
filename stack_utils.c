#include "monty.h"
#include <string.h>

/**
* _push - Entry Point
* @stack: stack to use
* @lineNumber: line number from file
* Description: Pushes arg from line number onto the stack
* Return: Nothing
*/
void _push(stack_t **stack, unsigned int lineNumber)
{
stack_t *newStackItem;
char *arg;
int push_arg = 0;

newStackItem = malloc(sizeof(stack_t));
if (!newStackItem)
{
printf("Error: malloc failed\n");
exitError(stack);
}

arg = strtok(NULL, "\n ");
if (isNumber(arg) == 1 && arg != NULL)
	push_arg = atoi(arg);

else
{
printf("L%d: usage: push integer\n", lineNumber);
exitError(stack);
}

if (stackBusy == 1)
	add_dnodeint_end(stack, push_arg);

if (stackBusy == 0)
	add_dnodeint(stack, push_arg);
}

/**
* _pall - Entry Point
* @stack: stack to use
* @lineNumber: line number from file
* Description: Pulls the items from the stack
* Return: Nothing
*/
void _pall(stack_t **stack, unsigned int lineNumber)
{
stack_t *stackList;

stackList = *stack;
while (stackList != NULL)
{
printf("%d\n", stackList->n);
stackList = stackList->next;
}

}