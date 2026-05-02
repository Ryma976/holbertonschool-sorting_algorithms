#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - heapify
 * @array: array
 * @size: total size
 * @i: index
 * @heap_size: heap size
 */
void sift_down(int *array, size_t size, size_t i, size_t heap_size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;

	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, heap_size);
	}
}

/**
 * heap_sort - sorts using heap sort
 * @array: array
 * @size: size
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
