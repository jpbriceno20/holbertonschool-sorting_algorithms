#include "sort.h"

/**
 * quick_sort - Sorts an array of integers using Quick sort
 * @array: Pointer to array
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive Quick sort
 * @array: Pointer to array
 * @low: Low index
 * @high: High index
 * @size: Array size for print_array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array
 * @low: Starting index
 * @high: Ending index (pivot)
 * @size: Size for printing
 *
 * Return: Pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low, j, temp;

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
	if (array[i] != array[high])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}
