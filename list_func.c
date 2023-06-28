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
