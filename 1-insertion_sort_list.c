#include "sort.h"

/**
 * Swap - swaps two doubly linked list nodes
 * @A: the first node
 * @B: the second node
 */

void Swap(listint_t *A, listint_t *B)
{
	if (A->prev != NULL)
		A->prev->next = B;
	if (B->next != NULL)
		B->next->prev = A;
	A->next = B->next;
	B->prev = A->prev;
	A->prev = B;
	B->next = A;
}

/**
 * insertion_sort_list - sorts in ascending order using insertion sort
 * @list: pointer to doubly linked list node
 * Only swapping is allowed
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *prev = NULL, *head;
	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
		return;
	head = *list;
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			curr = head->next;
			Swap(head, head->next);
			if (curr->prev == NULL)
				*list = curr;
			print_list((const listint_t *)*list);

			while (curr->prev != NULL)
			{
				if (curr->n >= curr->prev->n)
					break;
				prev = curr->prev;
				Swap(prev, curr);
				if (curr->prev == NULL)
					*list = curr;
				print_list((const listint_t *)*list);
			}
		}
		else
			head = head->next;
	}
}
