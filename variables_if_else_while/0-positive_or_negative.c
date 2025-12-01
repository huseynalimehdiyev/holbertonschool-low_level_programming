#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints whether a random number is positive, negative, or zero.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0)); /* Initialize random number generator */
	n = rand() - RAND_MAX / 2; /* Generate a random number */

	if (n > 0)
	{
		printf("%d is positive\n", n); /* n is positive */
	}
	else if (n == 0)
	{
		printf("%d is zero\n", n); /* n is zero */
	}
	else
	{
		printf("%d is negative\n", n); /* n is negative */
	}

	return (0);
}
