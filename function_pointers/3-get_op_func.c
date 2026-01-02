#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - selects the correct function for the operator
 * @s: operator string
 *
 * Return: pointer to the corresponding function, NULL if not found
 *
 * Description: Uses op_t array to match operator and return function.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (strcmp(s, ops[i].op) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
