#include "main.h"

void print_buffer(char buffer[], int *buffer_length);

/**
 * _printf - Printf function
 * @format: Format string.
 * Return: Number of printed characters.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	int flags, width, precision, size, buffer_length = 0;
	va_list list;
	char *buffer = NULL;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			if (buffer_length == 0)
				buffer = malloc(BUFF_SIZE * sizeof(char));

			buffer[buffer_length++] = format[i];
			if (buffer_length == BUFF_SIZE)
			{
				print_buffer(buffer, &buffer_length);
				buffer = realloc(buffer, BUFF_SIZE * sizeof(char));
			}

			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_length);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed_chars += handle_print(format, &i, list, buffer,
						      flags, width, precision, size);
		}
	}

	print_buffer(buffer, &buffer_length);
	free(buffer);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buffer_length: Length of the buffer.
 */
void print_buffer(char buffer[], int *buffer_length)
{
	if (*buffer_length > 0)
	{
		write(1, buffer, *buffer_length);
		*buffer_length = 0;
	}
}

