#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Index of the format specifier.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of printed characters or -1 on error.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char specifier = fmt[*ind];
	int printed_chars = -1;

	switch (specifier)
	{
		case 'c':
			return (print_char(list, buffer, flags, width, precision, size));
		case 's':
			return (print_string(list, buffer, flags, width, precision, size));
		case '%':
			buffer[0] = '%';
			buffer[1] = '\0';
			return (1);
		case 'i':
		case 'd':
			return (print_int(list, buffer, flags, width, precision, size));
		case 'b':
			return (print_binary(list, buffer, flags, width, precision, size));
		case 'u':
			return (print_unsigned(list, buffer, flags, width, precision, size));
		case 'o':
			return (print_octal(list, buffer, flags, width, precision, size));
		case 'x':
			return (print_hexadecimal(list, buffer, flags, width, precision, size));
		case 'X':
			return (print_hexa_upper(list, buffer, flags, width, precision, size));
		case 'p':
			return (print_pointer(list, buffer, flags, width, precision, size));
		case 'S':
			return (print_non_printable(list, buffer, flags, width, precision, size));
		case 'r':
			return (print_reverse(list, buffer, flags, width, precision, size));
		case 'R':
			return (print_rot13string(list, buffer, flags, width, precision, size));
		default:
			buffer[0] = '%';
			buffer[1] = specifier;
			buffer[2] = '\0';
			return (2);
	}
	return (printed_chars);
}

