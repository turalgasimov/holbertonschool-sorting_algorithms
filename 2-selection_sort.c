#include "sort.h"

/**
 * selection_sort - entry point
 * @array: array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t min, i, j;
	int tmp, swpd;

	for (i = 0; i < size - 1; i++)
	{
		swpd = 0;
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min == i)
			continue;
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		swpd = 1;
		if (swpd)
			print_array(array, size);
	}
}
