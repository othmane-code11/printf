#include "main.h"
/**
 * get_specifier - to find the forma of the funct.
 * @sp:  string format.
 *
 * Return: numbrs of chars printed.
 */

int (*get_specifier(char *sp))(va_list metalist, prmst_t *prmst)
{
	specifier_t specifier[] = {
		{ "c", print_char},
		{ "s", print_string},
		{ "i", print_int},
		{ "d", print_int},
		{ "b", print_binary},
		{ "%", print_percent},
		{ "o", print_octal},
		{ "S", print_S},
		{ "x", print_hex},
		{ "X", print_HEX},
		{ "p", print_address},
		{ "u", print_unsigned},
		{ "r", print_rev},
		{ "R", print_rot13},
		{NULL, NULL}
	};
	int x = 0;

	while (specifier[x].specifier)
	{
		if (*sp == specifier[x].specifier[0])
			return (specifier[x].f);
		x++;
	}
	return (NULL);
}

/**
 * get_print_func - selects the correct fct.
 * @sp: format string .
 * @metalist: ptr argument.
 * @prmst: paramtrs.
 * Return: pnt to a function.
 */
int get_print_func(char *sp, va_list metalist, prmst_t *prmst)
{
	int (*f)(va_list, prmst_t *) = get_specifier(sp);

	if (f)
	{
		return (f(metalist, prmst));
	}
	return (0);
}
/**
 * get_falg - finding flag.
 * @sp: string format.
 * @prmst: para struct.
 * Return: int..
 */

int get_falg(char *sp, prmst_t *prmst)
	int x = 0;

	switch (*sp)
	{
		case ' ':
			x = prmst->space_falg = 1;
			break;

		case '+':
			x = (*prmst.plus_falg) = 1;
			break;

		case '-':
			x = prmst->minus_falg = 1;
			break;


		case '#':
			x =  prmst->hashtag_falg = 1;
			break;

		case '0':
			x = (*prmst.zero_falg) = 1;
			break;
	}
	return (x);
}

/**
 * get_modifier - finding the modif func.
 * @sp: string format.
 * @prmst: struct param
 * Return: int.
 */

int get_modifier(char *sp, prmst_t *prmst)
{
	int x = 0;

	switch (*sp)
	{
		case 'l':
			x = prmst->l_modifier = 1;
			break;

		case 'h':
			x = prmst->h_modifier = 1;
			break;
	}
	return (x);

}
/**
 * get_whidth - select the whidth function.
 * @sp: string format.
 * @prmst: struct param.
 * @metalist: ptr.
 * Return: sp string.
 */

char *get_whidth(char *sp, prmst_t *prmst, va_list metalist)
{
	int r = 0;

	if (*sp == '*')
	{
		r = va_arg(metalist, int);
		sp++;
	}
	else
	{
		while (_isdigit(*sp))
		r = (r * 10) + (*sp++ - '0');
	}
	prmst->whidth = r;
	return (sp);
}

