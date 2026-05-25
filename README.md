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
   ```
   #include <ft_printf.h>
   ```

4. Compile your program with the library:
   ```bash
   cc my_program.c -I -L. -lftprintf -o my_program
   ```

# Resources

## List of resources

## LLM Usage Disclosure

## Tests performed

# Additional Section

## List of Functions and Explanation

### 🔹1 - Libc adapted functions 

#### Conversion / Manipulation / Verification

Name | Prototype | Description
--|--|--
[ft_atoi](./ft_atoi.c) | `int  ft_atoi(const char *nptr)` | Converts `nptr` to int