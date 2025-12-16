#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
    if (s=='\0')
        return 0;

    retrun (1 +_strlen_recursioN(s + 1));
}