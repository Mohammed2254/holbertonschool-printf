#include "main.h"
/**
 * _printf - Custom implementation of the standard printf function.
 * @format: String containing zero or more format specifiers.
 *
 * Description:
 * Parses the format string and handles supported conversion
 * specifiers. For each valid specifier, the corresponding argument
 * is fetched from the variadic argument list and printed.
 *
 * Supported specifiers:
 *   %d, %i  - Print integer values
 *   %c      - Print a character
 *   %s      - Print a string
 *   %%      - Print a literal percent sign
 *
 * Return:
 * Total number of characters printed.
 * Returns -1 if the format string is NULL.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
		if (format == NULL)
			return (-1);
va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
	i++;
		if (format[i] == 'd' || format[i] == 'i')
			count += print_int(args);
		else if (format[i] == 'c') /* if the format is 'c'(charater)*/
			count  += char_printing(args);
		else if (format[i] == '%') /* if the format was '%' (percent)*/
			count += percent_printing();
		else if (format[i] == 's')
			count += string_printing(args);
		else
			count += _putchar(format[i]);
		}
		else
		{
			count += _putchar(format[i]);
		}
	i++;
	}
va_end(args);
return (count);
}
