#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * string_printing - print a string from the given args
 * @args: the string that we want to print
 * Return: number of characters printed
 */

int string_printing(va_list args)
{
	int i;
	char *str = va_arg(args, char *);
	char ifNull[] = "(null)";

	if (str == NULL)
	{
		for (i = 0; i < 6; i++)
		{
			_putchar(ifNull[i]);
		}
		return (i);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
return (i);
}
