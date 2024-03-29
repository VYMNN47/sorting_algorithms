#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list.
 * @a: First node to swap.
 * @b: Second node to swap.
 *
 */

void swap(listint_t *a, listint_t *b)
{

	if (a->prev)
	{
		a->prev->next = b;
	}

	if (b->next)
	{
		b->next->prev = a;
	}

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using
 * the insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	iterator = (*list)->next;
	while (iterator)
	{
		current = iterator;
		iterator = iterator->next;
		while (current && current->prev)
		{
			if (current->prev->n > current->n)
			{
				swap(current->prev, current);
				if (current->prev == NULL)
				{
					*list = current;
				}

				print_list((const listint_t *)*list);
			}

			else
			{
				current = current->prev;
			}
		}
	}
}
