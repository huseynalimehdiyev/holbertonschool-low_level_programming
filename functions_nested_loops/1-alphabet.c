#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase
 *
 * Return: void
 */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
		_putchar(c);      /* 1-ci və yeganə döngə _putchar */

	_putchar('\n');       /* 2-ci _putchar */
}
