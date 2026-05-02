#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_subarray - Prints part of an array
 * @array: Array to print
 * @start: Starting index
 * @size: Number of elements to print
 */
void print_subarray(int *array, size_t start, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i)
			printf(", ");
		printf("%d", array[start + i]);
	}
	printf("\n");
}

/**
 * merge - Merges two sorted parts of an array
 * @array: Array to sort
 * @temp: Temporary array
 * @left: Left index
 * @mid: Middle index
 * @right: Right index
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_subarray(array, left, mid - left);
	printf("[right]: ");
	print_subarray(array, mid, right - mid);

	while (i < mid && j < right)
		temp[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

	while (i < mid)
		temp[k++] = array[i++];

	while (j < right)
		temp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_subarray(array, left, right - left);
}

/**
 * merge_sort_recursive - Sorts an array recursively
 * @array: Array to sort
 * @temp: Temporary array
 * @left: Left index
 * @right: Right index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = (left + right) / 2;
	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array using merge sort
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
