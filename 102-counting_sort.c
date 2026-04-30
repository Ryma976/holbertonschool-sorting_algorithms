#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to sort.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
