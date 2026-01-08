#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of argument types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
		printf("%s", sep);
		sep = ", ";

		if (format[i] == 'c' || format[i] == 'i')
			printf("%c", (format[i] == 'c') ? va_arg(args, int) : va_arg(args, int));

		if (format[i] == 'f' || format[i] == 's')
		{
			if (format[i] == 'f')
				printf("%f", va_arg(args, double));
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				printf("%s", str ? str : "(nil)");
			}
		}

		i++;
	}

	va_end(args);
	printf("\n");
}
