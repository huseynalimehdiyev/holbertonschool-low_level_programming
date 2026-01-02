#include <stdlib.h>
#include "dog.h"

/**
 * string_len - calculates the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 *
 * Description: This function loops through each character of the string
 *              until the null-terminator is found and counts the characters.
 */
int string_len(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;

	return (i);
}

/* copy string to new memory */
char *copy_string(char *s)
{
	int len, i;
	char *copy;

	if (!s)
		return (NULL);

	len = string_len(s) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = s[i];

	return (copy);
}

/* create new dog */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (!d)
		return (NULL);

	d->name = copy_string(name);
	if (name && !d->name)
	{
		free(d);
		return (NULL);
	}

	d->owner = copy_string(owner);
	if (owner && !d->owner)
	{
		if (d->name)
			free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;

	return (d);
}

/* print dog info */
#include <stdio.h>
void print_dog(dog_t *d)
{
	if (!d)
		return;

	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
