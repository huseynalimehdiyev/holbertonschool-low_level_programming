#include <stdio.h>

/**
 * main - prints all numbers of base 16 in lowercase
 *        followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 16; i++)
		putchar(i < 10 ? i + '0' : i - 10 + 'a');
	putchar('\n');

	return (0);
}
