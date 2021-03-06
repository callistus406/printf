#ifndef _FUNCS_ARRAY_
#define _FUNCS_ARRAY_

/*
*all the special characters for the printf function
*have been put in an associative array below
*
*/

print_t funcs[] = {
	{"c", print_char},
	{"s", print_string},
	{"d", print_int},
	{"i", print_int},
	{"u", print_unsigned},
	{"o", print_octal},
	{NULL, NULL}
}

#endif
