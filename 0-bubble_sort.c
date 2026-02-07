#include "sort.h"

/**
 * bubble_sort - entry point
 * @array: array
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, tmp, swpd;

	for (i = 0; i < size - 1; i++)
	{
		swpd = 0;
		for (j = 0; j < n - i -1; j++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				swpd = 1;
			}
		}

		if (!swpd)
			break;
	}
}
