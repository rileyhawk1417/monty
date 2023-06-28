#include "monty.h"

/**
* readFileByteCode - reads bytecode from file & runs command
* @filename: path to file (string arg)
* @stack: pointer to the top of stack(first/head)
* Description: This function reads the file given.
* Then processes the bytecode within it.
* Return: Nothing
*/
void readFileByteCode(char *filename, stack_t **stack)
{
char *buffer = NULL;
char *line;
instructionTable functionTable;
int lineCount = 1;
size_t idx = 0;
/*NOTE: Filestatus 0 means it closed, -1 means error */
int fileStatus;
ssize_t read = 1;
FILE *file = fopen(filename, "r");

if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exitError(stack);
}
while ((read = getline(&buffer, &idx, file)) != -1)
{
line = parseLine(buffer);
if (line == NULL || line[0] == '#')
{
lineCount++;
continue;
}
functionTable = getOpcodeFunc(line);
if (functionTable == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", lineCount, line);
exitError(stack);
}

functionTable(stack, lineCount);
lineCount++;
}

free(buffer);
fileStatus = fclose(file);
if (fileStatus == -1)
	exit(-1);
}

#include "monty.h"
/**
* getOpcodeFunc - Entry Poitn
* @str: character to check for opcode
* Description: This function gets the list of functions
* from the instructionTable
* Return: specified function
*/
instructionTable getOpcodeFunc(char *str)
{
int idx;
instruction_t instruction[] = {
{"push", _push},
{"pall", _pall},
{"pint", _pint},
{"pop", _pop},
{"swap", _swap},
{"add", _add},
{"nop", _nop},
/*TODO: add other opcode functions */
{NULL, NULL},
};

idx = 0;
while (instruction[idx].f != NULL && strcmp(instruction[idx].opcode, str) != 0)
{
idx++;
}
return (instruction[idx].f);
}

/**
* parseLine - Entry Point
* @line: char input from file
* Description: Parses the line of opcode from the file
* Return: character
*/
char *parseLine(char *line)
{
char *opcode;
opcode = strtok(line, "\n ");
if (opcode == NULL)
	return (NULL);

return (opcode);
}
