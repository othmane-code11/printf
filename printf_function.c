#include "main.h"
/**
 * print_char - print charac.
 * @metalist: argument pointer
 * @prmst: the paramters struct.
 * Return: number chars printed.
*/

int print_char(va_list metalist, prmst_t *prmst)
{
	char papachar = ' ';
	unsigned int papa = 1, rt = 0;
	unsigned int m = va_arg(metalist, int);

	if (prmst->minus_falg)
		rt += _putchar(m);
	while (papa++ < prmst->whidth)
		rt += _putchar(papachar);

	if (!prmst->minus_falg)
		rt += _putchar(m);
	return (rt);
}

/**
 * print_int - print & write integer.
 * @metalist: argument pointer
 * @prmst: the paramters struct.
 * Return: number of intgrs printed.
*/
int print_int(va_list metalist, prmst_t *prmst)
{
	long l;

	if (params->l_modifier)
		l = va_arg(metalist, long);

	else if (prmst->h_modifier)
		l = (short int)va_arg(metalist, int);

	else
		l = (int)va_arg(metalist, int);
	return (print_number(convert(l, 10, 0, prmst), prmst));
}
/**
 * print_percent - print & write percent.
 * @metalist: argument pointer
 * @prmst: the paramters struct.
 * Return: number of percent printed.
*/
int print_percent(va_list metalist, prmst_t *prmst)
{
	(void)prmst;
	(void)metalist;
	return (_putchar('%'));
}

/**
 * print_string - print string of char.
 * @metalist: argument pointer
 * @prmst: the paramters struct.
 * Return: numbr char printed.
*/
int print_string(va_list metalist, prmst_t *prmst)
{
	char *aaa = va_arg(metalist, char *), papachar = ' ';
	unsigned int papa = 0;
	unsigned int rt = 0, x = 0, y;
	(void)prmst;

	switch ((int)(!aaa))
		case 1:
			aaa = NULL_STRING;

	y = papa = _strlen(aaa);

	if (prmst->precision < papa)
		y = papa = prmst->precision;

	if (prmst->minus_falg)
	{
		if (prmst->precision != UINT_MAX)
			for (x = 0; x < papa; x++)
				rt += _putchar(*aaa++);
		else
			rt += _puts(aaa);
	}
	while (y++ < prmst->whidth)
		rt += _putchar(papachar);
	if (!prmst->minus_falg)
	{
		if (prmst->precision != UINT_MAX)
			for (x = 0; x < papa; x++)
				rt += _putchar(*aaa++);
		else
			rt += _puts(aaa);
	}
	return (rt);
}
/**
 * print_S - print specifier ...
 * @metalist: argument pointer
 * @prmst: the paramters struct.
 * Return: numbr char printed.
 */
int print_S(va_list metalist, prmst_t *prmst)

{

	char *aaa = va_arg(metalist, char *), char *oxa;
	int rt = 0;

	if ((int)(!aaa))
		return (_puts(NULL_STRING));
	for (; *aaa; aaa++)
	{
		if ((*aaa > 0 && *aaa < 32) || *aaa >= 127)
		{
			rt += _putchar('\\');
			rt += _putchar('x');
			oxa = convert(*aaa, 16, 0, prmst);
			if (!oxa[1])
				rt += _putchar('0');
			rt += _puts(oxa);
		}
		else
		{
			rt += _putchar(*aaa);
		}
		return (rt);
}
