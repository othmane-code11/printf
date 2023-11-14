#include "main.h"
/**
 * get_precision - get the precision from the format str .
 * @ptrn: forma str.
 * @prmst:struct prmst.
 * @metalist: ptr.
 * Return: pointer to a function.
 */
char *get_precision(char *ptrn, prmst_t *prmst, va_list metalist)
{
	if (*ptrn != '.')
		return (ptrn);
	ptrn++;
int r = 0;

	if (*ptrn == '*')
	{
		r = va_arg(metalist, int);
		ptrn++;
	}

else
	{
		while (_isdigit(*ptrn))
			r = (r * 10) + (*ptrn++ - '0');
	}
	prmst->precision = r;
	return (ptrn);
}

