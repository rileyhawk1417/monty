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

/**
 * _sub - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Subtract the two items at the top of the stack
 * Return: Nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
exitError(stack);
}

(*stack)->next->n -= (*stack)->n;
_pop(stack, line_number);
}

/**
 * _div - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Divide the two items at the top of the stack
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exitError(stack);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exitError(stack);
}

(*stack)->next->n /= (*stack)->n;
_pop(stack, line_number);
}

/**
 * _mul - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Multiply the two items at the top of the stack
 * Return: Nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exitError(stack);
}

(*stack)->next->n *= (*stack)->n;
_pop(stack, line_number);
}

/**
 * _mod - Entry Point
 * @stack: pointer to the stack for use
 * @line_number: line number from file
 * Description: Modulus of the two items at the top of the stack
 * Return: Nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exitError(stack);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exitError(stack);
}

(*stack)->next->n %= (*stack)->n;
_pop(stack, line_number);
}
