#include "main.h"

/**
 * print_alphabet - prints the lowercase alphabet followed by a new line
 *
 * Description: Uses _putchar to print each letter of the alphabet
 * followed by a newline. Only two _putchar calls are conceptually used:
 * one for letters (loop) and one for the newline.
 *
 * Return: void
 */
void print_alphabet(void)
{
	char c;

	c = 'a';
	while (c <= 'z')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
}
