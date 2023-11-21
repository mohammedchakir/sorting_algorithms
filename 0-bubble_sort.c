#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers in ascending order.
 *
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int img, moved;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		moved = 0;

		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				img = array[j];
				array[j] = array[j + 1];
				array[j + 1] = img;
				moved = 1;

				print_array(array, size);
			}
		}

	if (moved == 0)
	break;
	}
}
