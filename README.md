# _printf

A re-creation of the C standard library's `printf` function.  
This project implements a custom `_printf` that supports format specifiers, variable arguments, and output formatting identical to the original `printf`, following the specifications outlined by Holberton School.

## Supported Format Specifiers

- `%%` : Prints a literal percent sign (`%`)
- `%c` : Prints a single character
- `%s` : Prints a string
- `%d` / `%i` : Prints an integer (coming soon / implemented)

## Usage

Include the header file and call `_printf` like the standard `printf`:
