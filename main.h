#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct printer - format printer struct
 * @spec: the format specifier
 * @fn: the function that handles @spec
 */

typedef struct printer
{
	char *spec;
	int (*fn)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);

#endif
