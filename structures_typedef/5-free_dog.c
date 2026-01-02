#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory allocated for a dog_t struct
 * @d: pointer to the dog to free
 *
 * Return: Nothing
 *
 * Description: Frees the name and owner strings if they are not NULL,
 *              then frees the dog struct itself. Does nothing if d is NULL.
 */
void free_dog(dog_t *d)
{
	if (!d)
		return;

	if (d->name)
		free(d->name);

	if (d->owner)
		free(d->owner);

	free(d);
}
