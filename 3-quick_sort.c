#include "sort.h"

/**
 * quick_sort_recursive - Recursively applies quick sort using Lomuto partition
 * @array: Pointer to array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the full array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size);

/**
 * lomuto_partition - Lomuto partition scheme implementation
 * @array: Array of integers
 * @low: Starting index
 * @high: Pivot index
 * @size: Size of the full array (for printing)
 *
 * Return: Final pivot position after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Pointer to array
 * @size: Number of elements in the array
 *
 * Description: Uses the Lomuto partition scheme. Prints the array after
 * each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Helper function to perform quicksort recursively
 * @array: Array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of array for printing
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
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: Array of integers
 * @low: Starting index
 * @high: Pivot index
 * @size: Size of array for printing
 *
 * Return: Index of pivot after partitioning
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
