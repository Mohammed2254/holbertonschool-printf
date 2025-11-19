# `_printf` – Custom Implementation of `printf`

A custom re-implementation of the C standard library function `printf`, developed as part of the low-level programming curriculum at Holberton School.  
This project demonstrates a deep understanding of variadic functions, format specifiers, memory management, and system-level output using the `write` system call.

---

## ✨ Features

- Fully compatible with standard `printf` behavior for supported specifiers.
- Built using only allowed system calls (`write`) and standard C (ISO C90 compliant).
- Supports variable arguments via `<stdarg.h>`.
- Modular and well-documented codebase, designed for clarity and maintainability.

---

## 🔤 Supported Format Specifiers

| Specifier | Description                        |
|-----------|------------------------------------|
| `%%`      | Prints a literal `%` character     |
| `%c`      | Prints a single character          |
| `%s`      | Prints a null-terminated string    |
| `%d` / `%i` | Prints a signed decimal integer *(implemented)* |

> **Note**: Additional format specifiers (e.g., `%u`, `%x`, `%p`, field widths, flags) may be added in future extensions.

---
## Flow chart

                            ┌──────────────────────┐
                            │   Call _printf()     │
                            │ with format string   │
                            │ and variable args    │
                            └──────────┬───────────┘
                                       ▼
                    ┌─────────────────────────────────────┐
                    │ Initialize:                         │
                    │ - va_list args                      │
                    │ - char count = 0                    │
                    │ - parse format string character by  │
                    │   character                         │
                    └──────────────────┬──────────────────┘
                                       ▼
                      ┌──────────────────────────────────┐
                      │ Is current char == '%' ?         │
                      └──────────────────┬───────────────┘
                                No       │       Yes
                                 ▼       ▼
                ┌─────────────────────┐  ┌───────────────────────┐
                │ Write char via      │  │ Look at next char     │
                │ write()             │  │ (specifier)           │
                └─────────┬───────────┘  └───────────┬───────────┘
                          │                          ▼
                          │        ┌──────────────────────────────────┐
                          │        │ Which specifier?                 │
                          │        └────────────────┬─────────────────┘
                          │                         │
                          │          ┌──────────────┴───────────────┐
                          │          ▼              ▼               ▼
                          │   ┌─────────────┐ ┌────────────┐ ┌────────────┐
                          │   │ "%%"        │ │ "%c"       │ │ "%s"       │
                          │   │ → print '%' │ │ → print    │ │ → print    │
                          │   └─────┬───────┘ │   char     │ │   string   │
                          │         │         └─────┬──────┘ └─────┬──────┘
                          │         │               │              │
                          │         ▼               ▼              ▼
                          │   ┌─────────────┐ ┌────────────┐ ┌────────────┐
                          │   │ write('%')  │ │ write(c)   │ │ write(s)   │
                          │   └─────┬───────┘ └─────┬──────┘ └─────┬──────┘
                          │         │               │              │
                          │         └───────┬───────┴──────┬───────┘
                          │                 ▼              ▼
                          │        ┌──────────────────────────────────┐
                          │        │   "%d" or "%i" ?                 │
                          │        └────────────────┬─────────────────┘
                          │                         │
                          │              ┌──────────┴──────────┐
                          │              ▼                     ▼
                          │   ┌────────────────────┐  ┌────────────────────┐
                          │   │ Convert int to     │  │ (Other specifiers  │
                          │   │ string (e.g.,      │  │  not supported →   │
                          │   │  using _itoa)      │  │  ignore or error)  │
                          │   └─────────┬──────────┘  └────────────────────┘
                          │             ▼
                          │   ┌────────────────────┐
                          │   │ write(converted    │
                          │   │ number string)     │
                          │   └─────────┬──────────┘
                          │             │
                          └─────────────┴─────────────┐
                                        ▼
                     ┌──────────────────────────────────────┐
                     │ Increment char count by number of    │
                     │ bytes written                        │
                     └───────────────────┬──────────────────┘
                                         ▼
                   ┌───────────────────────────────────────────┐
                   │ Move to next character in format string │
                   └───────────────────┬───────────────────────┘
                                       ▼
                     ┌──────────────────────────────────────┐
                     │ End of format string?                │
                     └──────────────────┬───────────────────┘
                                No      │       Yes
                                 ▼      ▼
                                 └──────┴─────────►
                                               ▼
                                    ┌──────────────────────┐
                                    │ Return total char    │
                                    │ count (or -1 on err) │
                                    └──────────────────────┘


---
## 🚀 Usage

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Mohammed2254/holbertonschool-printf.git
   cd printf

## 📝 Contributors

The following students contributed to the design, implementation, and testing of this project:

- Mohammed Abdullah Alabdali  
- Reem Abdulhadi Alshehri  
- Abdullah Manahi Almouraibd
