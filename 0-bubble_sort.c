#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int tmp;
	int swapped = 1;

	if (array == NULL || size < 2)
		return;

	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		/* Optimization: the largest element is already at the end */
		len--;
	}
}
