#include <stdlib.h> /* malloc, free, NULL */
#include <stdio.h>  /* printf */
#include "dog.h"

/**
 * string_len - calculates the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 *
 * Description: Loops through each character of the string until the
 *              null-terminator is found.
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

/**
 * copy_string - allocates memory and copies a string
 * @s: the string to copy
 *
 * Return: pointer to the copied string, or NULL if it fails
 *
 * Description: Allocates memory for the string and copies each character.
 *              Includes the null-terminator. Returns NULL if malloc fails.
 */
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

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL if it fails
 *
 * Description: Allocates memory for a new dog structure.
 *              Makes deep copies of name and owner, sets the age,
 *              and handles allocation failures safely.
 */
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

/**
 * print_dog - prints a struct dog
 * @d: pointer to the dog to print
 *
 * Return: Nothing
 *
 * Description: Prints the name, age, and owner of the dog.
 *              Prints "(nil)" for name or owner if they are NULL.
 *              Does nothing if d is NULL.
 */
void print_dog(dog_t *d)
{
	if (!d)
		return;

	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
