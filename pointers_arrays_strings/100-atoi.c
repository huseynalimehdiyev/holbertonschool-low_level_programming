#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to string
 *
 * Return: integer value of the string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			/* avoid overflow: just accumulate as int */
			result = result * 10 + (s[i] - '0');
		}
		else if (started)
			break;
		i++;
	}

	return (result * sign);
}
