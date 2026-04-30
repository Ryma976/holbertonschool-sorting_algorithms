#include "sort.h"

/**
 * lomuto_partition - Scans the array and swaps elements based on pivot.
 * @array: The array to sort.
 * @size: Total size of the array (for printing).
 * @low: Starting index of the partition.
 * @high: Ending index (pivot location).
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_recursion - Recursive helper for quick_sort.
 * @array: The array to sort.
 * @size: Total size for printing.
 * @low: Starting index.
 * @high: Ending index.
 */
void quick_recursion(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, size, low, high);
		quick_recursion(array, size, low, pi - 1);
		quick_recursion(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array using the Quick sort algorithm.
 * @array: The array to sort.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursion(array, size, 0, (int)size - 1);
}
