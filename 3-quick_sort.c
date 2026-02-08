#include "sort.h"

void quick_sort_recursive(int *array, ssize_t low, ssize_t high,
		size_t size);
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high,
		size_t size);

/**
 * quick_sort - sorts an array of integers using Quick sort
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - recursive quick sort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high,
		size_t size)
{
	ssize_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index (pivot)
 * @size: size of the array
 *
 * Return: index of pivot
 */
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high,
		size_t size)
{
	int pivot, temp;
	ssize_t i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}
