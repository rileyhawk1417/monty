#include "monty.h"

#include <stdio.h>
#include <stdlib.h>
/**
* add_dnodeint - Entry point
* @head: Doubly Linked List
* @n: int value
* Return: stack_t list & new node
* Description: Adds new node at start of doubly linked list
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *newNode;
stack_t *start;

newNode = malloc(sizeof(stack_t));
if (newNode == NULL)
	return (NULL);

newNode->n = n;
newNode->prev = NULL;
start = *head;

if (start != NULL)
{
while (start->prev != NULL)
	start = start->prev;
}

newNode->next = *head;
if (start != NULL)
	start->prev = newNode;
*head = newNode;
return (newNode);
}

/**
* add_dnodeint_end - Entry point
* @head: Doubly Linked List
* @n: int value
* Return: stack_t list & new node
* Description: Adds new node at end of doubly linked list
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
stack_t *newNode;
stack_t *end;

newNode = malloc(sizeof(stack_t));
if (newNode == NULL)
	return (NULL);

newNode->n = n;
newNode->next = NULL;
end = *head;

if (end != NULL)
{
while (end->next != NULL)
	end = end->next;

end->next = newNode;
}
else
{
*head = newNode;
}
newNode->prev = end;
return (newNode);
}

/**
* delete_dnodeint_at_index - Entry point
* @head: Doubly Linked List
* @index: id of target node
* Return: 0 on success, 1 on fail
* Description: Get a node value from the list with index
* then add a new value after
*/
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
stack_t *targetNode = *head;
stack_t *tmpNode;
unsigned int count = 0;

if (targetNode != NULL)
while (targetNode->prev != NULL)
	targetNode = targetNode->prev;

while (targetNode != NULL)
{
if (count == index)
{
if (count == 0)
{
*head = targetNode->next;
if (*head != NULL)
	(*head)->prev = NULL;
}
else
{
tmpNode->next = targetNode->next;
if (targetNode->next != NULL)
	targetNode->next->prev = tmpNode;
}

free(targetNode);
return (1);
}

tmpNode = targetNode;
targetNode = targetNode->next;
count++;
}

return (-1);
}

/**
* free_dlistint - Entry point
* @head: Doubly Linked List
* Return: nothing
* Description: Free up the doubly linked list
*/
void free_dlistint(stack_t *head)
{
stack_t *node;

if (head != NULL)
	while (head->prev != NULL)
		head = head->prev;

while ((node = head) != NULL)
{
head = head->next;
free(node);
}

}
