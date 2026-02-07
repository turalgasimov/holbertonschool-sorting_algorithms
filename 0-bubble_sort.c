#include "sort.h"

/**
 * bubble_sort - entry point
 * @array: array
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp, swpd;

	for (i = 0; i < size - 1; i++)
	{
		swpd = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				swpd = 1;
			}
		}

		if (!swpd)
			break;
	}
}
