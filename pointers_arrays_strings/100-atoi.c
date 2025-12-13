#include "main.h"
#include <stdint.h>
#include <limits.h>

/**
 * _atoi - converts a string to an integer safely
 * @s: string to convert
 *
 * Return: the converted integer
 */
int _atoi(char *s)
{
	int sign = 1;
	int found_digit = 0;
	int64_t num = 0;

	/* Blank line after declarations */
	while (*s)
	{
		if (*s == '-' && !found_digit)
		{
			sign = -sign;
		}
		else if (*s >= '0' && *s <= '9')
		{
			int digit = *s - '0';

			/* Blank line after declaration */
			found_digit = 1;
			num = num * 10 + digit;
		}
		else if (found_digit)
		{
			break;
		}

		s++;
	}

	if (sign == 1 && num > INT_MAX)
	{
		return (INT_MAX);
	}
	else if (sign == -1 && -num < INT_MIN)
	{
		return (INT_MIN);
	}

	return ((int)(sign * num));
}
