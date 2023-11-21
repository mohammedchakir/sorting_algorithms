#include "sort.h"

void swap_integers(int *first, int *second);
int qs_partition(int *array, size_t size, int left, int right);
void qs_sort(int *array, size_t size, int left, int right);

/**
 * swap_integers - function swap two integers in an array.
 * @first: The fst integer to swap.
 * @second: The scnd integer to swap.
 */
void swap_integers(int *first, int *second)
{
	int snapshot;

	snapshot = *first;
	*first = *second;
	*second = snapshot;
}

/**
 * qs_partition - function quiet the array in size, low and high
 * @array: the array to print
 * @size: the size to introduce
 * @low: the low parameter
 * @high: the high parameter
 *
 * Return: The final partition index.
 */
int qs_partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_integers(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_integers(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * qs_sort - Implement the quicksort algorithm through recursion.
 * @array: the array to print
 * @size: the size to print
 * @low: the low parameter
 * @high: the high parameter
 *
 * Description: Uses the Lomuto partition scheme.
 */
void qs_sort(int *array, size_t size, int low, int high)
{
	int partition;

	if (low < high)
	{
		partition = qs_partition(array, size, low, high);
		qs_sort(array, size, low, partition - 1);
		qs_sort(array, size, partition + 1, high);
	}
}

/**
 * quick_sort - function quick sort
 * @array: the array to print
 * @size: the size to print
 *
 * Description: Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs_sort(array, size, 0, size - 1);
}
