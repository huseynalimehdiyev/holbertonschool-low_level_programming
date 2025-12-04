#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		if (n / 10 != 0)
			print_number(-(n / 10));
		_putchar('0' + -(n % 10));
	}
	else
	{
		if (n / 10 != 0)
			print_number(n / 10);
		_putchar('0' + n % 10);
	}
}
