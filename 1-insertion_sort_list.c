#include "sort.h"

/**
 * insertion_sort_list - entry point
 *@list: list
 */
void insertion_sort_list(listint_t **list)
{
	int key;
	listint_t *j, *l = *list;

	l = l->next;
	while (l)
	{
		key = l->n;
		j = l->previous;

		while (j && (j->n > key))
		{
			if (l->next)
			{
				j->next = l->next;
				l->next->previous = j;
			} else
			{
				j->next = NULL;
			}
			if (j->previous)
			{
				l->previous = j->previous;
				j->previous->next = l;
			} else
			{
				l->previous = NULL;
			}
			j = l->previous;
		}
		l = l->next;
	}
}
