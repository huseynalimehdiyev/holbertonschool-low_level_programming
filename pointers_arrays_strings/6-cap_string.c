#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @s: The string to modify
 *
 * Return: A pointer to the modified string
 */
char *cap_string(char *s)
{
    int i = 0, j;
    char separators[] = " \t\n,;.!?\"(){}";

    while (s[i] != '\0')
    {
        /* Capitalize first character if lowercase */
        if (i == 0 && (s[i] >= 'a' && s[i] <= 'z'))
        {
            s[i] -= 32;
        }

        /* If current char is a separator, capitalize next char */
        for (j = 0; separators[j] != '\0'; j++)
        {
            if (s[i] == separators[j] && (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
            {
                s[i + 1] -= 32;
                break;
            }
        }
        i++;
    }
    return (s);
}
