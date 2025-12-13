#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @s: Pointer to the string to modify
 *
 * Description: Words are separated by space, tab, newline,
 * comma, semicolon, period, exclamation mark, question mark,
 * double quote, parenthesis, and curly braces.
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char separators[] = " \t\n,;.!?\"(){}";

	while (s[i] != '\0')
	{
		/* Capitalize first character if lowercase */
		if (i == 0 && (s[i] >= 'a' && s[i] <= 'z'))
			s[i] -= 32;

		/* If current char is a separator, capitalize next char */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (s[i] == separators[j] &&
			    (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
			{
				s[i + 1] -= 32;
				break;
			}
		}
		i++;
	}
	return (s);
}
