#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, sets it to zero
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: pointer to allocated memory, or NULL on failure
 * or if nmemb or size is 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size, i;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	p = ptr;
	for (i = 0; i < total_size; i++)
		p[i] = 0;

	return (ptr);
}

