#include <stdio.h>

/**
 * main - finds and prints the largest prime factor
 *        of the number 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	long n = 612852475143;
	long i;

	/* Remove all factors of 2 */
	while (n % 2 == 0)
		n /= 2;

	/* Check odd factors from 3 onwards */
	for (i = 3; i * i <= n; i += 2)
	{
		while (n % i == 0)
			n /= i;
	}

	/* If remaining n is a prime number greater than 2 */
	if (n > 2)
		printf("%ld\n", n);
	else
		printf("%ld\n", i - 2);

	return (0);
}
