#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: pointer to string
 *
 * Return: integer value
 */
int _atoi(char *s)
{
	int i;
	int sign;
	unsigned long acc;
	unsigned long neg_limit;

	i = 0;
	sign = 1;
	acc = 0;
	neg_limit = (unsigned long)INT_MAX + 1UL;

	/* handle signs before digits */
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	/* build absolute value in acc (unsigned) */
	while (s[i] >= '0' && s[i] <= '9')
	{
		acc = acc * 10UL + (unsigned long)(s[i] - '0');

		if (sign == 1 && acc > (unsigned long)INT_MAX)
			return (INT_MAX);
		if (sign == -1 && acc > neg_limit)
			return (INT_MIN);

		i++;
	}

	if (sign == -1)
		return ((int)(- (long)acc));
	return ((int)acc);
}
