#include "main.h"

/**
 * print_numbers - prints the numbers from 0 to 9, followed by a new line.
 *
 * Return: void
 */
void print_numbers(void)
{
	char numbers[] = "0123456789\n";
	int i = 0;

	while (numbers[i] != '\0')
	{
		_putchar(numbers[i]);
		i++;
	}
}
