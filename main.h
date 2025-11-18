#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int char_printing(va_list args);
int string_printing(va_list args);
int int_printing(va_list args);
int percent_printing(void);
int _putchar(char c);

int print_int(va_list args);
int print_number(unsigned int num);

#endif/*MAIN_H*/
