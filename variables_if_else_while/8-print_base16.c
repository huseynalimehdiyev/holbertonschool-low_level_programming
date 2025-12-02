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

	for (i = 0; i < 10; i++)
		putchar(i + '0');    // 0–9

	for (i = 0; i < 6; i++)
		putchar(i + 'a');    // a–f

	putchar('\n');

	return (0);
}
