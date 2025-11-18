#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * char_printing - prints a character
 * @args: argument list
 * Return: 1 (number of characters printed).
 */

int char_printing(va_list args)
{
    int c = va_arg(args, int);
    int result = (write(1, &c, 1));
   
    if (result == -1)
        return (-1);
    else
        return (result);
    
}

