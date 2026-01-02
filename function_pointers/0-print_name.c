#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a given function
 * @name: name to print
 * @f: pointer to a function that takes a string and returns void
 *
 * Return: Nothing
 *
 * Description: If f is not NULL, calls the function f with name as argument.
 *              If f is NULL, does nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!f)
		return;

	f(name);
}
