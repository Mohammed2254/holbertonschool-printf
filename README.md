# `_printf` – Custom Implementation of `printf`

A custom re-implementation of the C standard library function `printf`, developed as part of the low-level programming curriculum at **Holberton School**.  
This project demonstrates a deep understanding of **variadic functions**, **format specifiers**, **manual output handling**, and system-level I/O using the `write` system call — all within **ISO C90** compliance.

---
## 📁 Project Files

| File                  | Purpose                                                                          |
|-----------------------|----------------------------------------------------------------------------------|
| `main.h`              | Header file with function prototypes and includes (`<unistd.h>`, `<stdarg.h>`).  |
| `_printf.c`           | Core function that parses the format string and dispatches specifiers.           |
| `char_printing.c`     | Implements `%c` – prints a single character.                                     |
| `string_printing.c`   | Implements `%s` – prints a null-terminated string.                               |
| `int_printing.c`      | Implements `%d` and `%i` – prints signed integers.                               |
| `percent_printing.c`  | Implements `%%` – prints a literal `%`.                                          |
| `helpingFunc.c`       | Utility functions: _putchar (write wrapper) and print_number (recursively prints integers).. |    

## ✨ Features

- Matches the behavior of standard printf for the supported specifiers in most common cases.
- Built **without** standard I/O functions (`printf`, `puts`, etc.); uses only the `write` system call.
- Implements **variadic arguments** via `<stdarg.h>`.
- The project is structured into small, focused source files for clarity.
- Returns the **total number of characters printed**, or `-1` on error (e.g., `NULL` format string).

---

## 🔤 Supported Format Specifiers

| Specifier      | Description                      |
|----------------|----------------------------------|
| `%%`           | Prints a literal `%` character   |
| `%c`           | Prints a single character        |
| `%s`           | Prints a null-terminated string  |
| `%d` / `%i`    | Prints a signed decimal integer  |

> **Note**: Additional specifiers (e.g., `%u`, `%x`, `%p`, flags, width/precision) are **not implemented** in this version but may be added in future extensions.

---

## 🧠 Project Structure Overview

- **`main.h`**: Header file containing function prototypes and necessary includes (`<unistd.h>`, `<stdarg.h>`).
- **`_printf.c`**: Core implementation of `_printf`, which parses the format string and delegates printing tasks.
- **Helper functions** (defined in separate `.c` files, not shown here but assumed):
  - `char_printing()` – handles `%c`
  - `string_printing()` – handles `%s`
  - `print_int()` – handles integrprinting logic
  - `print_number() – recursively prints integer digit.`
  - `percent_printing()` – handles `%%`
  - `_putchar()` – wrapper around `write()` for single-character output

> All printing is done using `write(1, ...)` to ensure compliance with Holberton’s low-level restrictions.


## 🔵 Flowchart of _printf Function (Text Representation)
graph TD
    A[Start: _printf(format, ...)] --> B{format == NULL?};

    B -- Yes --> C[Return -1];
    B -- No --> D[int i = 0, count = 0];

    D --> E[va_start(args, format)];

    E --> F{format[i] != '\0'?};

    F -- No --> J[va_end(args)];
    J --> K[Return count];

    F -- Yes --> G{format[i] == '%'};

    G -- No --> H[count += _putchar(format[i])];
    H --> I[i++];
    I --> F;

    G -- Yes --> L{format[i + 1] == '\0'};

    L -- Yes --> C;

    L -- No --> M[i++ (Skip '%')];

    M --> N{format[i] == 'd' or 'i'};

    N -- Yes --> O[count += print_int(args)];
    N -- No --> P{format[i] == 'c'};

    O --> I;
    
    P -- Yes --> Q[count += char_printing(args)];
    P -- No --> R{format[i] == '%'};
    
    Q --> I;
    
    R -- Yes --> S[count += percent_printing()];
    R -- No --> T{format[i] == 's'};
    
    S --> I;
    
    T -- Yes --> U[count += string_printing(args)];
    T -- No --> V[count += _putchar('%'); count += _putchar(format[i])];
    
    U --> I;
    V --> I;

## 🚀 Usage

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Mohammed2254/holbertonschool-printf.git
   cd holbertonschool-printf
---
   ## Compile
   - gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o printf_test
---
## 🚀 Usage

To use `_printf` in your program:

1. Include the header:
   ```c
   #include "main.h"
   int main(void)
   {
    _printf("Hello %s! You are %d years old.\n", "Ali", 25);
    return 0;
   }
---

## 📝 Contributors

The following students contributed to the design, implementation, and testing of this project:

- Mohammed Abdullah Alabdali  
- Reem Abdulhadi Alshehri  
- Abdullah Manahi Almouraibd
