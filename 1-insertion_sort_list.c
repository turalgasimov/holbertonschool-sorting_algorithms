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
		j = l->prev;

		while (j && (j->n > key))
		{
			if (l->next)
			{
				j->next = l->next;
				l->next->prev = j;
			} else
			{
				j->next = NULL;
			}
			if (j->previous)
			{
				l->prev = j->prev;
				j->prev->next = l;
			} else
			{
				l->prev = NULL;
			}
			j = l->prev;
		}
		l = l->next;
	}
}
