#include "sort.h"

/**
 * swap_ints - Function swap two integers in an array.
 * @a: The fst integer to swap.
 * @b: The scnd integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Function sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of all integers.
 * @size: The size of the array printed.
 *
 * Description: Uses the Knuth interval sequence for discription.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
