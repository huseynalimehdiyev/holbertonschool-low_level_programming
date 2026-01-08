#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of argument types
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *s, *sep = "";

	va_start(ap, format);

	while (format && format[i])
	{
		while (format[i] == 'c' || format[i] == 'i'
		       || format[i] == 'f' || format[i] == 's')
		{
			printf("%s", sep);
			sep = ", ";

			if (format[i] == 'c')
				printf("%c", va_arg(ap, int));
			if (format[i] == 'i')
				printf("%d", va_arg(ap, int));

			if (format[i] == 'f')
				printf("%f", va_arg(ap, double));

			if (format[i] == 's')
			{
				s = va_arg(ap, char *);
				printf("%s", s ? s : "(nil)");
			}
			break;
		}
		i++;
	}

	va_end(ap);
	printf("\n");
}
