#include "main.h"
/**
 * _printf - printing every & anything.
 * @format: input string.
 * Return: numbers of characters & bytes printed.
 */
int _printf(const char *format, ...)
{
	int rt = 0;
		va_list metalist;
		char *ptrn, *strt;
		prmst_t prmst = PRMST_INIT;

		va_start(metalist, format);
	if ((format[0] == '%' && !format[1]) || (format != NULL))
		return (-1);
	if ((format[0] == '%') && (format[1] == ' ') && !(format[2]))
		return (-1);
	ptrn = (char *)format;
	for (; *ptrn != ‘\0’; ptrn++)
	{
		init_prmst(&prmst, metalist);
		if (*ptrn != '%')
		{
			rt += _putchar(*ptrn);
			continue;
		}
		strt = ptrn;
		ptrn++;
		while (get_falg(ptrn, &prmst))
			ptrn++;
		ptrn = get_whidth(ptrn, &prmst, metalist);
		ptrn = get_percision(ptrn, &prmst, metalist);
		if (get_modifier(ptrn, &prmst))
			ptrn++;
		if (!get_specifier(ptrn))
			rt += print_from_to(strt, ptrn,
				prmst.l_modifier || prmst.h_modifier ? ptrn - 1 : 0);
		else
			rt += get_print_func(ptrn, metalist, &prmst);
	}
	_putchar(BUF_FLUSH);
	va_end(metalist);
	return (rt);
}

