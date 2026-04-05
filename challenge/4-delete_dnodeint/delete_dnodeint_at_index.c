#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */ 
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		if ((*head)->next != NULL) /* head is not last in list */
			{
			(*head)->next->prev = (*head)->prev; /* point head's next's prev to head's prev */
			(*head)->prev->next = (*head)->next; /* point head's prev's next to head's next */
			}
		else /* head is last on list (head's next is NULL) */
			{
			(*head)->prev->next = NULL; /* point head's prev's next to NULL (make it the tail) */
			}
		*head = saved_head;
		free(*head); /*  free node after pointer reassignments*/
	}
	return (1);
}