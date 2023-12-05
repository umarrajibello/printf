#include "main.h"

/**
 * _printf - Prints a formated string to the stdout.
 * @format: Const string to be printed to output.
 *
 * Return: Number of charaters printed.
 */

int _printf(const char *format, ...)
{
	/* count to store count chars printed, i for iteration */
	int count = 0, i;
	va_list f_spec;
	/*function pointer to receive function for printing specific case*/
	int (*fptr)(va_list);

	if (format == NULL)
		return (-1);

	va_start(f_spec, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			/*get appropriate function for specified format specifier*/
			fptr = select_fun(format[i + 1]);
			if (fptr == NULL)
				count += write(1, &format[i], 1);
			else
			{
				count += fptr(f_spec);
				i++;
			}
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(f_spec);
	return (count);
}
