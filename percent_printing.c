#include "main.h"
#include <unistd.h>
/**
 * percent_printing - Prints a single percent sign ('%') to stdout.
 *
 * Return: Number of characters printed (always 1).
 */
int percent_printing(void)
{
    return write(1, "%", 1);
}
