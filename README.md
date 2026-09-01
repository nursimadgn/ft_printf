*This project has been created as part of the 42 curriculum by seldogan.*

# ft_printf

## Description
The **ft_printf** project is a fundamental milestone in the 42 curriculum. The goal is to recode the standard libc `printf()` function without buffer management, producing a static library named `libftprintf.a`.

This project deepens the understanding of **variadic functions** (`<stdarg.h>`), call stack mechanisms, recursive number formatting, base conversions (hexadecimal and decimal), and pointer representation in C.

### Mandatory Conversions Handled
* `%c` : Prints a single character.
* `%s` : Prints a string (handles `NULL` safely).
* `%p` : Prints a `void *` pointer argument in hexadecimal format.
* `%d` : Prints a decimal (base 10) signed integer.
* `%i` : Prints an integer in base 10.
* `%u` : Prints an unsigned decimal (base 10) number.
* `%x` : Prints a number in lowercase hexadecimal (base 16).
* `%X` : Prints a number in uppercase hexadecimal (base 16).
* `%%` : Prints a literal percent sign.

---

## Instructions

### Compilation
Compile the library using the provided `Makefile`:

```bash
make
```

### Makefile Rules
* `make` / `make all` : Compiles the source files and creates `libftprintf.a`.
* `make clean` : Deletes all object files (`.o`).
* `make fclean` : Deletes object files and the generated `libftprintf.a`.
* `make re` : Recompiles the library from scratch.

### Execution & Testing
To link `libftprintf.a` with your own test file:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o printf_test
./printf_test
```

---

## Algorithm and Data Structure Explanation

### 1. Variadic Arguments & Stack Traversal
Because `ft_printf(const char *format, ...)` accepts a variable number of parameters, the macros provided by `<stdarg.h>` are utilized:
* `va_list` acts as a cursor pointer pointing into the program call stack where arguments are pushed.
* `va_start` initializes the pointer to the first variadic argument immediately following `format`.
* `va_arg` retrieves the argument value by casting the data at the current stack location to the requested type, advancing the cursor forward by `sizeof(type)`.
* `va_end` cleans up the variadic argument list state.

### 2. Linear Parser & Dispatcher
1. **Format Traversal:** The function linearly parses the string byte by byte.
2. **Standard Output:** Regular characters are written directly to standard output via `write(1, &c, 1)` and increment the character counter by 1.
3. **Specifier Dispatcher (`ft_findformat`):** When a `%` symbol is found, the subsequent character is evaluated. `ft_findformat` passes the `va_list` reference to the appropriate printing helper (`ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_unsigned_putnbr`, `ft_putnbr_base`, `ft_putadress`).
4. **Length Counting:** Each helper function returns the exact number of bytes successfully printed, allowing `ft_printf` to maintain an accurate tally matching standard `printf` behavior.

---

## Resources

### References
* [C Variadic Functions - cppreference.com](https://en.cppreference.com/w/c/variadic)
* [Variable Arguments in C/C++ - Medium](https://medium.com/@sddkal/c-cpp-de%C4%9Fi%C5%9Fken-say%C4%B1da-arg%C3%BCman-alan-fonksiyonlar-e8eae4c0e2d6)
* [Variadic Functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
* Stackoverflow
* Youtube
* Man 3

### AI Usage
* **Documentation Structuring:** AI was used to format the README according to the 42 subject requirements.
* **Edge Case Clarifications:** AI was consulted to clarify edge-case behaviors (such as `NULL` pointer handling for `%p` vs `%s` across different OS platforms).
* **Code Implementation:** All algorithms, Makefile configuration, and variadic stack handling were written, tested, and validated manually.

## Tester
* [printfTester by Tripouille](https://github.com/Tripouille/printfTester)