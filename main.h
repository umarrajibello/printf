#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/*PROTOTYPES*/

int _printf(const char *, ...);
int _strlen(char *);
int prnt_char(va_list);
int prnt_dec(va_list);
int prnt_pec(va_list);
int prnt_str(va_list);
int (*select_fun(char))(va_list);

/*STRUCTS*/

/**
 * struct funcs - Stores functions to be used on string.
 * @sp: The specifiers indentity.
 * @func: The function to be called.
 */

typedef struct funcs
{
	char *sp;
	int (*func)(va_list);
} spec_op;

#endif /* MAIN_H */
