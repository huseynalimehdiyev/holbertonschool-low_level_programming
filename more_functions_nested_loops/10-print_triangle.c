#include "main.h"

/**
 * print_triangle - prints a right-aligned triangle using #
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int count = 1;
	int spacecount = 1;
	int a;

	if (size > 0)
	{
		for (count = 1; count <= size; count++)
		{
			for (spacecount = 1; size - count >= spacecount; spacecount++)
				_putchar(' ');
			for (a = 1; a <= count; a++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
