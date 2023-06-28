#include "monty.h"
#include <stdlib.h>

/**
* exitError - Entry Point
* @stack: Stack that throws the error
* Description: Frees up the stack
* then returns the exits with an error
*/
void exitError(stack_t **stack)
{
if (*stack)
	free_dlistint(*stack);
exit(EXIT_FAILURE);
}

/**
* isNumber - Entry Point
* @str: char value
* Description: Frees up the stack
* then returns the exits with an error
* Return: Int
*/
int isNumber(char *str)
{
unsigned int idx = 0;
if (str == NULL)
	return (0);

while (str[idx])
{

if (str[0] == '-')
{
idx++;
continue;
}

if (!isdigit(str[idx]))
	return (0);

idx++;
}
return (1);
}

/**
 * _rotl - Entry Point
 * @stack: The stack to use
 * @line_number: line number from file 
 * Description: Flip the stack to the top
 * Return: Nothing
 */
void _rotl(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
stack_t *stackList;
int valueA, valueB;

if (*stack == NULL)
	return;

stackList = *stack;
while (stackList->next)
	stackList = stackList->next;

while (stackList)
{
if (!stackList->next)
{
valueA = stackList->n;
stackList->n = (*stack)->n;
}
else
{
valueB = stackList->n;
stackList->n = valueA;
valueA = valueB;
}
stackList = stackList->prev;
}

}

/**
 * _rotr - Entry Point
 * @stack: The stack to use
 * @line_number: line number from file 
 * Description: Flip the stack to the bottom
 * Return: Nothing
 */
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
stack_t *stackListA, *stackListB;
int valueA, valueB;

if (*stack == NULL)
	return;

stackListA = *stack;
stackListB = *stack;
while (stackListA->next)
	stackListA = stackListA->next;

while (stackListB)
{
if (stackListB->prev == NULL)
{
valueA = stackListB->n;
stackListB->n = stackListA->n;
}
else
{
valueB = stackListB->n;
stackListB->n = valueA;
valueA = valueB;
}
stackListA = stackListB->next;
}

}
