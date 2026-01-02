#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @action: pointer to the function to apply to each element
 *
 * Return: Nothing
 *
 * Description: Loops through the array and applies the function
 *              pointed to by action on each element.
 *              Does nothing if array, action is NULL or size is 0.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || !action || size == 0)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
