#include "sort.h"

/**
 * selection_sort - Sorts an array using Selection sort
 * @array: Pointer to the array
 * @size: Number of elements in the array
 *
 * Description: Prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
