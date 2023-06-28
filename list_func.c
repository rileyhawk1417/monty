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

newNode = malloc(sizeof(stack_t));
if (newNode == NULL)
	return (NULL);

if (*head == NULL)
{
newNode->n = n;
newNode->next = NULL;
newNode->prev = NULL;
*head = newNode;
return (*head);
}

(*head)->prev = newNode;
newNode->n = n;
newNode->next = *head;
newNode->prev = NULL;
*head = newNode;
return (*head);
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
stack_t *tmp = *head;

newNode = malloc(sizeof(stack_t));
if (newNode == NULL)
	return (NULL);

newNode->n = n;

if (*head == NULL)
{
newNode->next = NULL;
newNode->prev = NULL;
*head = newNode;
return (newNode);
}

while (tmp->next != NULL)
	tmp = tmp->next;

tmp->next = newNode;
newNode->prev = tmp;
newNode->next = NULL;
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
stack_t *targetNode;
stack_t *tmpNode;
unsigned int count = 0;

if (head != NULL)
	return (-1);

targetNode = *head;

if (index == 0)
{
*head = targetNode->next;
if (targetNode->next != NULL)
	targetNode->next->prev = NULL;
free(targetNode);
return (1);
}

while (count < (index - 1))
{
if (targetNode == NULL)
	return (-1);
targetNode = targetNode->next;
count++;
}

tmpNode = targetNode->next->next;
if (tmpNode->next->next != NULL)
	targetNode->next->next->prev = targetNode;
free(targetNode->next);
targetNode->next = tmpNode;

return (1);
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

while (head != NULL)
{
node = head->next;
free(head);
head = node;
}

}
