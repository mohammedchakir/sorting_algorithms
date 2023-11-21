#include "sort.h"

void swap_node_front(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_front - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_front(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *current = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = current;
	else
		*list = current;
	current->prev = (*shaker)->prev;
	(*shaker)->next = current->next;
	if (current->next != NULL)
		current->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = current;
	current->next = *shaker;
	*shaker = current;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *current = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = current;
	else
		*tail = current;
	current->next = (*shaker)->next;
	(*shaker)->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = current;
	current->prev = *shaker;
	*shaker = current;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (swapped == false)
	{
		swapped = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_front(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}
