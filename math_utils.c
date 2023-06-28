#include "monty.h"

/**
 * _add - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file 
 * Description: Add the two items at the top of the stack
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exitError(stack);
}

(*stack)->next->n += (*stack)->n;
_pop(stack, line_number);
}
