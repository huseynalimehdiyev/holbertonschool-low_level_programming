#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a valid password for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
	int sum;
	char c;

	srand(time(NULL));
	sum = 0;

	while (sum < 2772)
	{
		c = rand() % 94 + 33; /* printable ASCII: 33 to 126 */

		if (sum + c > 2772)
			c = 2772 - sum;

		putchar(c);
		sum += c;
	}

	return (0);
}
