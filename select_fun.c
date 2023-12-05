#include "main.h"

/**
 * select_fun - Selects a function to decide what it prints.
 * @spec: The specifier recieved from _printf.
 *
 * Return: The proper function needed for the formatted string.
 */

int (*select_fun(char spec))(va_list)
{
	int i;

	spec_op ptrS[] = {
		{"c", prnt_char},
		{"s", prnt_str},
		{"%", prnt_pec},
		{"d", prnt_dec},
		{"i", prnt_dec},
		{NULL, NULL}
	};

	for (i = 0; ptrS[i].sp != NULL; i++)
	{
		if ((*(ptrS[i].sp) == spec))
			return (ptrS[i].func);
	}
	return (NULL);
}
