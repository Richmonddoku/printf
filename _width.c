#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;

	if (is_digit(format[*i + 1]))
	{
		while (is_digit(format[*i + 1]))
		{
			width *= 10;
			width += format[*i + 1] - '0';
			(*i)++;
		}
	}
	else if (format[*i + 1] == '*')
	{
		(*i)++;
		width = va_arg(list, int);
	}

	return (width);
}

