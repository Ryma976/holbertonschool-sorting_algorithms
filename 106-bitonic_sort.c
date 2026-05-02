#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two ints
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - merges bitonic sequence
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t i, k = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + k; i++)
		{
			if ((dir == 1 && array[i] > array[i + k]) ||
				(dir == 0 && array[i] < array[i + k]))
			{
				swap(&array[i], &array[i + k]);
				print_array(array, size);
			}
		}
		bitonic_merge(array, size, start, k, dir);
		bitonic_merge(array, size, start + k, k, dir);
	}
}

/**
 * bitonic_sort_rec - recursive sort
 */
void bitonic_sort_rec(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t k = seq / 2;

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size,
			dir ? "UP" : "DOWN");
		print_array(array + start, seq);

		bitonic_sort_rec(array, size, start, k, 1);
		bitonic_sort_rec(array, size, start + k, k, 0);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size,
			dir ? "UP" : "DOWN");
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - sorts using bitonic sort
 * @array: array
 * @size: size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_rec(array, size, 0, size, 1);
}
