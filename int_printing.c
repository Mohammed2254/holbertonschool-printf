#include "main.h"
/**
	* print_int - Prints an integer using only _putchar
	* @args: A va_list containing the next argument to print
	*
	* Description:
	* This function handles printing both %d and %i format specifiers.
	* It takes an integer from the argument list, converts it to characters,
	* prints them one-by-one, and returns the number of printed characters.
	*
	* Return: Number of characters printed
	*/
int print_int(va_list args)
{
int n = va_arg(args, int); /* Get the integer from the argument list */
unsigned int num;
int count = 0;
/* If number is negative, print the minus sign and convert to positive */
if (n < 0)
{
_putchar('-');
count++;
num = -n;  /* Convert to positive for further processing */
}
else
{
num = n;
}
/* Print the digits of the number */
count += print_number(num);
return (count);
}
/**
	* print_number - Recursively prints an unsigned integer
	* @num: The number to print
	*
	* Description:
	* This helper function prints each digit of an unsigned integer.
	* It uses recursion to reach the most significant digit first.
	*
	* Example:
	* num = 123 → calls:
	* print_number(12) → print_number(1) → print '1' then '2' then '3'
	*
	* Return: Number of characters printed
	*/
int print_number(unsigned int num)
{
int count = 0;
/* If number has more than one digit, recursively print all but last */
if (num / 10)
count += print_number(num / 10);
/* Print the last digit */
_putchar((num % 10) + '0');
count++;
return (count);
}
