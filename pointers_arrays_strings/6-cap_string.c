#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: input string
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i;
	int sep;

	char separators[] = " \t\n,;.!?\"(){}";

	i = 0;
	if (s[i] >= 'a' && s[i] <= 'z')
		s[i] -= 32;

	i = 1;
	while (s[i] != '\0')
	{
		sep = 0;
		for (int j = 0; separators[j] != '\0'; j++)
		{
			if (s[i - 1] == separators[j])
				sep = 1;
		}

		if (sep && s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;

		i++;
	}

	return (s);
}
