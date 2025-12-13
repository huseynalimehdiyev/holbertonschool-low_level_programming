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
	int i = 0;
	int sign = 1;
	long result = 0; /* long istifadə edirik overflow yoxlamaq üçün */

	/* handle signs before digits */
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	/* build number */
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');

		if (sign == 1 && result > INT_MAX)
			return (INT_MAX);
		if (sign == -1 && -result < INT_MIN)
			return (INT_MIN);

		i++;
	}

	return ((int)(result * sign));
}
