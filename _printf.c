#include "main.h"
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
i++;
if (format[i] == 'd' || format[i] == 'i')
count += print_int(args);
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
