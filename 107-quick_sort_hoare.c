#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers
 * @a: first
 * @b: second
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - partition using Hoare scheme
 * @array: array
 * @size: total size (for printing)
 * @low: left index
 * @high: right index
 *
 * Return: partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_rec - recursive quick sort
 * @array: array
 * @size: total size
 * @low: left index
 * @high: right index
 */
void quick_sort_rec(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, size, low, high);
		quick_sort_rec(array, size, low, p);
		quick_sort_rec(array, size, p + 1, high);
	}
}

/**
 * quick_sort_hoare - main function
 * @array: array
 * @size: size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, size, 0, size - 1);
}
