*This project has been created as part of the 42 curriculum by jduque-n.*

![Static Badge](https://img.shields.io/badge/C%20standard-C89-orange?style=flat&logo=github)

![Static Badge](https://img.shields.io/badge/Compiler-clang-blue?style=flat&logo=github)

# Description

The ft_printf project consists in a very exact and faithful recreation of the *printf* function stored in the standard libc library using the C89 Standard. The original printf function has its application defined by the input of flags, width of input and precision (_e.g. %-10.5..._) followed by the specifier chosen (e.g. %... d, c, i, s). However, due to time constraints, this version only operates without the ability to process additional flags, only works with given specifiers. A complete version of ft_printf will be updated as soon as possible. 

# Instructions

## Requirements

For ft_printf to be properly complied and executed, the following requirements must be met:

- Unix-based system (Linux, but macOS is also possible)
- A C language compiler (`clang` is normally used);
- `make` command installed;

## How to compile

The following set of commmands will allow to perform the following actions

Command | Description
--|--|--
`make`, `make all` | Compiles and generates the `libftprintf.a` library for use
`make clean`| Eliminates the .o files generated
`make fclean`| Eliminates the .o files and the `libftprintf.a` library generated
`make re`| Rebuilds the library and .o files from scratch (used when changes are committed to the program .c files) 

## How to extract project from Repository (GitHub)

To extract the necessary files to generate the libftprintf.a library in any computer and to use it, the following commands must the executed:

1. Clone the repository:
   ```bash
   git@github.com:josemariafernandes1-commits/ft_printf.git
   ```

2. Build the library:
   ```bash
   make -C ft_printf
   ```

3. Include the header in your C file (to test):
   ```bash
   #include <ft_printf.h>
   ```

4. Compile your program with the library:
   ```bash
   cc my_program.c -L. -lftprintf -o my_program
   ```

## Example of usage of printf in a function

Let's say you want to use the printf command to output a message in the terminal. You have to write a program named `my_program` with a defined use in the main, such as:

```bash
#include "ft_printf.h" // The <> are only used when we have clearly defined source folders, not in this case //

int main(void)
{
	ft_printf("Hello world\n");
	ft_printf("%s\n", "Hello world");
	return (0);
}
```
Now, you have to compile the function and obtain the object file frm linking to its static library from ft_printf. This command should generate an object filen amed as you wish:

```bash
cc my_program.c -L. -lftprintf -o my_program // Since the header and the makefile are in the same directory, no need for -I //
```

Now, to execute the object file generated:

```bash
./my_program
```

If the function is working properly, you should get the following output:

Hello world
Hello world

# Explanation of print

This folllowing section will describe how a printf works in theory, I'm including here the section about additional flags, although this current version does not process them.

## Format Specification

A regular summoning of the flags for a specification conversion, has the following structure:

% (First appeared) | Additional flags | Width of output characters | Precision | Conversion specifier
--|--|--|--|--
Mandatory | Optional | Optional | Optional | Mandatory

```bash
%[ad.flags][width][precision]specifier
```

Each different category bears different rules for which characters can be used. Below is an explanation of how each input alters the result output

### Additional flags

Symbols | Description
--|--
`-` | Left-aligns the value, depending on a width value, with spaces as ocnvention. By default, if there's no `-`, the output is right-aligned.
`+` | Adds the respective sign of the number on the output. By default, only negative numbers are prepended.
`[space]` | Adds spaces depending on width value for positive numbers only, but only if there's no `+` flag used previously.
`#` | Adds the prefix of `0x` or `0X` associated with `x` and `X` specifiers, for hexadecimal numbers different than zero.
`0` | Adds prepended zeroes to for values associated with specifiers `d`, `i`, `u`, `x` and `X`. Does not register if the flag `-` is present or is limited by precision. 

### Width

Symbols | Description
--|--
`[number]` | Defines the minimum number of characters that is required to be printed. If the provided value in the specifier has less characters than what is defined in the width, the output is either prepended with spaces by default or appended with spaces if the `-` flag is present on its input structure. If the value is bigger than the width, then is passed without processing.
`*` | If the `*` character is present, then the width value is not specified within the format specification, but an an extra integer number that is provided before the argument is pronounced.

### Precision

Symbols | Description
--|--
`.[number]` | Depending on the specifier, if defines the maximum number of a given unit to be printed, without truncating the original value. A value of precision of zero indicates that no zeroes that are prepended or appended can be outputted. For the specifiers `d`, `i`, `u`, `x` and `X`, if defines the maximum of digits to be written, but if the value is shorter than its precision value, the output is padded with zeroes. For specifier `s`, it defines the maximum number of characters to be printed, including spaces. If no value is prsent after inserting the `.` declaration, the precision is considered equal to zero.
`.*` | If the `*` character is present, then the precision value is not specified within the format specification, but an an extra integer number that is provided before the argument is pronounced.
 
### Specifiers

Symbols | Description
--|--
% | Writes the character `%`.
c | Writes the character defined in the argument.
d or i | Writes an integer/decimal (base 10) signal-defined number.
x or X | Writes an hexadecimal number, with the prefix `0x`or `0X`.
s | Writes a string.
u | Writes an unsigned number as a decimal number.
p | Writes the pointer address to void defined in the stack when allocated for a given variable as an hexadecimal number with the prefix present.

# Resources

## List of resources

- `man` command explanations;
- LLM consultation (Google Gemini AI, Claude Code [main source]);
- Collaboration with peers;
- Apaptation of existing README.md files from other GitHub/Codeberg users;
- [printf format identifiers.](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html)
- [(PDF)Secrets of “printf”](https://www.academia.edu/10297206/Secrets_of_printf_)
- [Printf Format String Visualizer](https://zhxnlai.github.io/printf/#/)

## LLM Usage Disclosure

Throughout the completion of this module, Gemini and Claude were mostly used by the user to help learn on a first-hand basis the important concepts regarding variadic functions, including the declaration of va_list, va_start, va_arg, va_copy and va_end. Claude code was also used to analyse the behavior of prototype functions for this module when the testing of functions was not so easily reproducible. In a general sense, the LLM modules were used as makeshift tutors to faciitate the allocation of time for the undestanding of these concepts.

## Tests performed

- Claude code (Pro Version), for explaining how to execute varaidic functions and suggestions on the type of function to write to complete the assignment.
- [francinette](https://github.com/xicodomingues/francinette.git), created by [@xicodomingues](https://github.com/xicodomingues)

# Additional Section

## List of Functions and Explanation

### 🔹1 - Main file functions 

Name | Prototype | Description
--|--|--
[ft_printf](./ft_printf.c) | `int	ft_printf(const char *format, ...)` | Initiates the reading of the arguments provided, based on the existance of flags, width, precision elements and the specifier provided. If only a string is provided, it writes the eintre string. THe return type includes the provided input in a written output and the result total of bytes written.
[ft_dispatch_helpers](./ft_dispatch_helpers.c) | `static int	ft_dispatch_helpers(const char *format, va_list args)` | If a specifier is defined, it dispatches the input to its selected specifier function to process it as according to the rules of the base printf function.

### 🔹2 - Handler functions

Name | Prototype | Description
--|--|--
[ft_handle_c](./ft_handle_c.c) | `int	ft_handle_c(int character)` | If a %c specifier is used, it simply prints the first character present (or if it is the only one present).
[ft_handle_di_base10](./ft_handle_di_base10.c) | `int	ft_handle_di_base10(int number)` | Prints the integer or decimal number as a written string.
[ft_handle_hex](./ft_handle_hex.c) | `int	ft_handle_hex(unsigned int hex_number, char caps_lock)` | After receiving an unsigned integer number, it prints that number written in a hexadecimal format, with the option to print the alpha section of the hexadecimal base as upper or lower-cased.
[ft_handle_s](./ft_handle_s.c) | `int	ft_handle_s(char *string)` | Outputs the printable contents of the provided string.
[ft_handle_u_base10](./ft_handle_u_base10.c) | `int	ft_handle_u_base10(unsigned int number)` | Prints the integer or number in the form of an unsigned integer. The lower limit of the integers, -2147483648, is reversed so that when going backwards from zero, the -1 is converted into the max 4294967295, as according to bit nomenclature, which is 2147483647 * 2 + 1.
[ft_handle_void_hex](./ft_handle_void_hex.c) | `int	ft_handle_void_hex(void *pointer)` | Prints the void pointer address associated in memory in hexadecimal format

### 🔹3 - Auxiliary functions

Name | Prototype | Description
--|--|--
[ft_putnbr](./ft_putnbr.c) | `static int	ft_putnbr(int nb)` | Converts the integer into a string format, then prints it.
[ft_putnbr_hex](./ft_putnbr_hex.c) | `static int	ft_putnbr_hex(long nb, char *base)` | Converts the integer into a hexadecimal format (with lower or upper case letters of its base), then prints it.
[ft_strlen](./ft_strlen.c) | `static size_t	ft_strlen(const char *str)` | Prints an entire string (standard libc function).
[ft_putnbr_unsigned](./ft_putnbr_unsigned.c) | `static int	ft_putnbr_unsigned(unsigned int nb)` | Same operation as ft_putnbr, but it turns it's negative input into postive output.