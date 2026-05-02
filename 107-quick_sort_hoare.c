#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions an array using Hoare scheme
 * @array: Array to partition
 * @size: Size of the array
 * @left: Left index
 * @right: Right index
 *
 * Return: Partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot;
	int i;
	int j;

	pivot = array[right];
	i = left - 1;
	j = right + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * quick_sort_recursive - Sorts an array recursively
 * @array: Array to sort
 * @size: Size of the array
 * @left: Left index
 * @right: Right index
 */
void quick_sort_recursive(int *array, size_t size, int left, int right)
{
	int part;

	if (left < right)
	{
		part = hoare_partition(array, size, left, right);
		quick_sort_recursive(array, size, left, part - 1);
		quick_sort_recursive(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array using quick sort Hoare partition
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
