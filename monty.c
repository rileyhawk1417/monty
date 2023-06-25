#include "monty.h"
/**
 * main - Entry Point
 * @argCount: number of arguments
 * @args: file argument
 * Return: 0
 */
int main(int argCount, char *args[])
{
stack_t *stack;
stack = NULL;
if (argCount != 2)
{
printf("Usage: monty file\n");
exitError(&stack);
}
readFileByteCode(args[1], &stack);
free_dlistint(stack);
return (0);
}
