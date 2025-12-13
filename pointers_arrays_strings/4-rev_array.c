#include "main.h"

/**
 * reverse_array - reverses the first n elements of an array
 * @a: array of integers
 * @n: number of elements to reverse
 */
void reverse_array(int *a, int n)
{
	int i;
	int tmp;

	for (i = 0; i < n / 2; i++)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}
