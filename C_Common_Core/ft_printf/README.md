*This project has been created as part of the 42 curriculum by nuakmurz *

# ft_printf

## Description

`ft_printf` is a custom implementation of the standard C `printf()` function, created as part of the 42 Warsaw Common Core curriculum.

The main goal of this project is to understand how formatted output works internally without using the original `printf()` function.

The project focuses on:

* Variadic functions
* Format string parsing
* Type conversion
* Decimal and hexadecimal number representation
* Pointer formatting
* Output using the `write()` system call
* Tracking and returning the number of printed characters
* Creating and using a static library

The function processes a format string character by character. When it finds a `%` character, it checks the following conversion specifier, extracts the corresponding argument using `va_arg()`, and prints it using the appropriate helper function.

---

## Supported Conversions

| Conversion | Description                                                   |
| ---------- | ------------------------------------------------------------- |
| `%c`       | Prints a single character                                     |
| `%s`       | Prints a string                                               |
| `%d`       | Prints a signed decimal integer                               |
| `%i`       | Prints a signed decimal integer                               |
| `%u`       | Prints an unsigned decimal integer                            |
| `%x`       | Prints an unsigned hexadecimal number using lowercase letters |
| `%X`       | Prints an unsigned hexadecimal number using uppercase letters |
| `%p`       | Prints a pointer address in hexadecimal format                |
| `%%`       | Prints a percent sign                                         |

The function prototype is:

```c
int	ft_printf(const char *format, ...);
```

Like the original `printf()`, `ft_printf()` returns the total number of characters printed.

---

## Instructions

### Compilation

Clone the repository:

```bash
git clone https://github.com/nuakmurz/ft_printf.git
cd ft_printf
```

Compile the project:

```bash
make
```

This command creates the static library:

```text
libftprintf.a
```

### Makefile Rules

Compile the project:

```bash
make
```

Remove object files:

```bash
make clean
```

Remove object files and the static library:

```bash
make fclean
```

Recompile the entire project:

```bash
make re
```

### Using the Library

Create a `main.c` file:

```c
#include "ft_printf.h"

int	main(void)
{
	int	number;

	number = 42;
	ft_printf("Hello, %s!\n", "42 Warsaw");
	ft_printf("Character: %c\n", 'A');
	ft_printf("Number: %d\n", number);
	ft_printf("Unsigned: %u\n", 42U);
	ft_printf("Hexadecimal: %x\n", number);
	ft_printf("Pointer: %p\n", &number);
	ft_printf("Progress: 100%%\n");
	return (0);
}
```

Compile the test program with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o ft_printf_test
```

Run the executable:

```bash
./ft_printf_test
```

Example output:

```text
Hello, 42 Warsaw!
Character: A
Number: 42
Unsigned: 42
Hexadecimal: 2a
Pointer: 0x...
Progress: 100%
```

---

## Algorithm and Data Structure

### Main Algorithm

The main algorithm scans the format string from left to right using an integer index.

For every character:

1. If the current character is not `%`, it is printed directly.
2. If the current character is `%` and another character follows it, the index moves to the conversion specifier.
3. The conversion specifier is passed to `ft_format()`.
4. `ft_format()` selects the correct helper function.
5. The helper function prints the corresponding argument.
6. The number of printed characters is added to the total length.
7. After reaching the null terminator, the function returns the total number of printed characters.

Simplified flow:

```text
Format string
      |
      v
Read one character
      |
      +-- Normal character --> Print directly
      |
      +-- '%' character --> Read conversion specifier
                                 |
                                 v
                           Select helper function
                                 |
                                 v
                           Print the argument
                                 |
                                 v
                       Add printed length to total
```

### Why This Algorithm Was Chosen

A single left-to-right traversal is suitable because the format string must be processed in its original order.

This approach is simple and efficient:

* Each character is inspected only once.
* Arguments are consumed only when a conversion specifier is found.
* Output order matches the order of the format string.
* No copy of the complete format string is required.
* No dynamic memory allocation is required.

If the format string contains `n` characters, the parsing complexity is approximately:

```text
O(n)
```

Number conversion functions require additional time depending on the number of digits. For a number with `d` digits, printing it requires:

```text
O(d)
```

### Variadic Argument Structure

The project uses `va_list` from `<stdarg.h>`.

```c
va_list	args;
```

The variadic argument list is initialized with:

```c
va_start(args, format);
```

Arguments are extracted according to their expected type:

```c
va_arg(args, int);
va_arg(args, unsigned int);
va_arg(args, char *);
va_arg(args, void *);
```

After all arguments are processed, the list is closed with:

```c
va_end(args);
```

`va_list` was chosen because the number and types of arguments passed to `ft_printf()` are not fixed.

### Conversion Dispatch

The `ft_format()` function acts as a dispatcher.

It checks the conversion character and calls the matching output function:

```text
%c --> ft_putchar_len()
%s --> ft_putstr_len()
%d --> ft_putnbr_len()
%i --> ft_putnbr_len()
%u --> ft_putunsigned_len()
%x --> ft_puthex_len()
%X --> ft_puthex_len()
%p --> ft_ptr_helper()
%% --> ft_putchar_len()
```

This structure was chosen to keep `ft_printf()` focused on parsing while helper functions handle individual conversions.

It also makes the implementation easier to test and maintain.

### Number Conversion Algorithm

Decimal and hexadecimal values are printed recursively.

For a decimal number:

1. Divide the number by `10`.
2. Recursively print the remaining digits.
3. Print the final digit using the remainder from division by `10`.

Example:

```text
1234
 |
 +-- print 123
 |      |
 |      +-- print 12
 |             |
 |             +-- print 1
 |
 +-- print 4
```

For hexadecimal values, the same algorithm is used with base `16`.

The hexadecimal digit set is selected according to the conversion:

```text
%x --> 0123456789abcdef
%X --> 0123456789ABCDEF
```

Recursion was chosen because it prints digits in the correct left-to-right order without allocating an additional string or buffer.

### Pointer Conversion

A pointer is retrieved as:

```c
void *
```

It is then converted to an unsigned integer type large enough to represent an address:

```c
unsigned long
```

For a non-null pointer:

1. Print the `0x` prefix.
2. Print the address in lowercase hexadecimal.

For a null pointer:

```text
(nil)
```

is printed.

Pointer values are represented in hexadecimal because this is the conventional representation used by `printf("%p", pointer)` on the target environment.

### Data Structures

This project does not require complex data structures such as linked lists, arrays, stacks, or trees.

The main data used by the implementation consists of:

* A `va_list` for accessing variadic arguments
* Integer indexes for scanning the format string
* Integer counters for tracking the output length
* Character pointers for strings
* Unsigned integer types for unsigned, hexadecimal, and pointer values

This minimal structure was chosen because arguments can be processed sequentially and printed immediately. Storing all arguments before printing would add unnecessary complexity and memory usage.

---

## Technical Choices

### Direct Output with `write()`

The project uses the `write()` system call through helper functions.

This provides direct control over every printed character and avoids using the original `printf()` implementation.

### Returning Printed Length

Each helper function returns the number of characters it prints.

For example:

```c
int	ft_putchar_len(char c);
int	ft_putstr_len(const char *str);
int	ft_putnbr_len(int n);
```

The return values are added together inside `ft_printf()`.

This design ensures that the final return value matches the behavior of the standard `printf()` function.

### Separate Helper Functions

Each conversion type has a separate helper function.

This separation provides:

* Smaller functions
* Easier debugging
* Easier testing
* Clearer responsibility
* Better code reuse

### No Dynamic Memory Allocation

The implementation prints values directly instead of converting them into dynamically allocated strings.

As a result:

* No `malloc()` is required
* No `free()` is required
* Memory leaks are avoided
* The implementation remains lightweight

---

## Edge Cases

The implementation handles several important edge cases.

### Null Format String

```c
ft_printf(NULL);
```

The function returns:

```text
-1
```

### Null String

A null string passed to `%s` should be handled by `ft_putstr_len()`.

Example:

```c
ft_printf("%s\n", NULL);
```

Expected output:

```text
(null)
```

### Null Pointer

```c
ft_printf("%p\n", NULL);
```

Expected output:

```text
(nil)
```

### Minimum and Maximum Integers

```c
ft_printf("%d\n", INT_MIN);
ft_printf("%d\n", INT_MAX);
```

The implementation must correctly handle:

```text
-2147483648
2147483647
```

### Maximum Unsigned Integer

```c
ft_printf("%u\n", 4294967295U);
```

Expected output:

```text
4294967295
```

### Consecutive Conversions

```c
ft_printf("%c%s%d%x\n", 'A', "test", 42, 255);
```

Expected output:

```text
Atest422a
```

---

## Project Structure

```text
ft_printf/
├── Makefile
├── README.md
├── ft_printf.c
├── ft_printf.h
├── ft_putchar_len.c
├── ft_putstr_len.c
├── ft_putnbr_len.c
├── ft_putunsigned_len.c
├── ft_puthex_len.c
└── ft_putpointer_len.c
```

The exact file structure may vary depending on how helper functions are organized.

---

## Testing

The custom implementation can be compared with the original `printf()`.

```c
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	ft_length;
	int	printf_length;
	int	number;

	number = 42;
	ft_length = ft_printf(
			"Mine: %c %s %d %i %u %x %X %p %%\n",
			'A', "Hello", -42, 42, 42U, 255, 255, &number);

	printf_length = printf(
			"Original: %c %s %d %i %u %x %X %p %%\n",
			'A', "Hello", -42, 42, 42U, 255, 255, &number);

	printf("ft_printf length: %d\n", ft_length);
	printf("printf length: %d\n", printf_length);
	return (0);
}
```

The displayed output and returned lengths should be compared.

The program can also be checked with Valgrind:

```bash
valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	./ft_printf_test
```

---

## Limitations

This implementation covers the mandatory part of the 42 `ft_printf` project.

The following bonus features are not implemented:

* Field width
* Precision
* Left alignment
* Zero padding
* `#` flag
* Space flag
* `+` flag

Examples of unsupported formatting:

```c
printf("%10d", 42);
printf("%.5d", 42);
printf("%-10s", "Hello");
printf("%05d", 42);
printf("%#x", 42);
printf("%+d", 42);
```

---

## Resources

The following resources were used to understand the concepts required for this project:

* Linux manual page for variadic arguments:

```bash
man stdarg
```

* Linux manual page for `write()`:

```bash
man 2 write
```

* Linux manual page for `printf()`:

```bash
man 3 printf
```

* C standard library documentation for variadic functions
* GNU C Library documentation
* cppreference documentation about variadic functions
* 42 project subject and evaluation requirements
* Documentation about decimal and hexadecimal number systems

Useful topics for further study:

* Variadic functions in C
* Format string parsing
* Integer promotion in variadic functions
* Signed and unsigned integer representation
* Base conversion algorithms
* Pointer representation
* Static libraries
* Makefiles

### Use of AI

AI was used as a learning and review tool during the project.

It was used for:

* Explaining how `va_list`, `va_start`, `va_arg`, and `va_end` work
* Clarifying the expected behavior of conversion specifiers
* Explaining pointer formatting and null-pointer behavior
* Reviewing test cases and edge cases
* Helping identify possible mistakes during debugging
* Improving the structure and clarity of this README
* Explaining the algorithm used for recursive decimal and hexadecimal output

AI was not used to replace the implementation process. The project code was written, tested, and understood by the author. AI-generated explanations and suggestions were reviewed before being applied.