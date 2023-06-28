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
