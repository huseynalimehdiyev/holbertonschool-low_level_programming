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
	int result;
	int limit;

	i = 0;
	sign = 1;
	result = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	limit = (sign == -1) ? INT_MIN : -INT_MAX;

	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result < (limit + (s[i] - '0')) / 10)
			return (limit);

		result = result * 10 - (s[i] - '0');
		i++;
	}

	if (sign == 1)
		result = -result;

	return (result);
}
