#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *curr, *next, *tmp;

	if (list == NULL || *list == NULL)
		return;
	curr = *list;
	while (curr)
	{
		next = curr->next;

		/* Fully detach curr */
		curr->prev = NULL;
		curr->next = NULL;

		/* Insert at beginning of sorted list */
		if (sorted == NULL || curr->n <= sorted->n)
		{
			curr->next = sorted;
			if (sorted)
				sorted->prev = curr;
			sorted = curr;
		}
		else
		{
			tmp = sorted;
			while (tmp->next && tmp->next->n < curr->n)
				tmp = tmp->next;

			curr->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = curr;

			tmp->next = curr;
			curr->prev = tmp;
		}

		*list = sorted;
		print_list(*list);
		curr = next;
	}
}
