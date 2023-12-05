#include "main.h"

/**
 * prnt_char - prints a character.
 * @f_spec: va_list variable..
 *
 * Return: returns the count of chars printed.
 */
int prnt_char(va_list f_spec)
{
	char c = va_arg(f_spec, int);

	return (write(1, &c, 1));
}

/**
 * prnt_str - prints a string
 * @f_spec: va_list variable..
 *
 * Return: returns the count of chars printed.
 */
int prnt_str(va_list f_spec)
{
	int length = 0;
	char *str = va_arg(f_spec, char *);

	if (str == NULL)
		str = "(null)";

	while (str[length] != '\0')
		length++;
	return (write(1, str, length));
}

/**
 * prnt_pec - prints percent symbols.
 * @f_spec: va_list variable..
 *
 * Return: return the number of chars printed.
 */
int prnt_pec(va_list __attribute__((__unused__))f_spec)
{
	char c = '%';

	return (write(1, &c, 1));
}

/**
 * prnt_dec - prints a number
 * @f_spec: va_list variable
 *
 * Return: returns the number of digits printed
 */
int prnt_dec(va_list f_spec)
{
	int num = (int)va_arg(f_spec, int);
	char l_digit, c;
	int num_rev = 0, no_digits = 0, count = 0;

	/* store last digit to avoid overflow & handle -*/
	if (num < 0)
	{
		c = '-';
		count += write(1, &c, 1);
		l_digit = ('0' - (num % 10));
		num /= -10;
	}
	else
	{
		l_digit = ((num % 10) + '0');
		num /= 10;
	}

	/* reversing the number */
	for (no_digits = 0; (num > 0); no_digits++)
	{
		num_rev *= 10;
		num_rev += (num % 10);
		num /= 10;
	}

	/* print reversed no. */
	for (; (num_rev > 0); no_digits--)
	{
		c = ((num_rev % 10) + '0');
		count += write(1, &c, 1);
		num_rev /= 10;
	}
	for (; no_digits != 0; no_digits--)
		putchar('0');
	count += write(1, &l_digit, 1);
	return (count);
}
