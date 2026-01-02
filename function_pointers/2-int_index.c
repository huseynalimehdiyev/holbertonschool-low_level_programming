#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array using a comparison function
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @cmp: pointer to the function used to compare values
 *
 * Return: index of the first element for which cmp does not return 0,
 *         -1 if no element matches or if size <= 0 or array/cmp is NULL
 *
 * Description: Loops through the array and applies the cmp function on
 *              each element. Returns the index of the first match.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || !cmp || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
