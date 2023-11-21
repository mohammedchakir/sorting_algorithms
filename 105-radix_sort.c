#include "sort.h"

void radix_sort(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
int get_max(int *array, size_t size);

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 *               with the LSD (Least Significant Digit) algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}

/**
 * counting_sort_radix - Sorts an array of integers using Counting sort
 *                      for a specific digit place
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The digit place (power of 10)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count;
	int i;

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	count = malloc(10 * sizeof(int));
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}

/**
 * get_max - Finds the maximum value in an array
 *
 * @array: The array to be searched
 * @size: Number of elements in @array
 *
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
