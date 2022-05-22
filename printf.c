#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * printSpecials - displays special characters
 * @next: character after the percent sign
 * @arg: argument
 * Return: shows no of chars
 */

int printSpecials(char next, va_list arg)
{
	int functsIndex;

	specialsStruct functs[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"b", print_unsignedToBinary},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{NULL, NULL}
	};

	for (functsIndex = 0; functs[functsIndex].indentifier != NULL; functsIndex++)
	{
		if (functs[functsIndex].indentifier[0] == next)
			return (functs[functsIndex].printer(arg));
	}
	return (0);
}

/**
 * _printf - mimic printf from stdio
 * Description: produces result dependin on the format
 * write output to stdout, the standard output stream
 * @format: character string composed of zero 
 *
 * Return: the number of characters displayed
 * (excluding the null byte used to end output to strings)
 * return -1 for incomplete specials error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int specialsPrinted = 0, charPrinted = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			charPrinted++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			charPrinted++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		specialsPrinted = printSpecials(format[i + 1], arg);
		if (specialsPrinted == -1 || specialsPrinted != 0)
			i++;
		if (specialsPrinted > 0)
			charPrinted += specialsPrinted;

		if (specialsPrinted == 0)
		{
			_putchar('%');
			charPrinted++;
		}
	}
	va_end(arg);
	return (charPrinted);
}
