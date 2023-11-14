#include "main.h"
/**
 * convert - convert the functions.
 * @numb: number .
 * @bases: base lik.
 * @falgs: arg flages.
 * @prmst: prmst structures.
 * Return: str string.
 */

char *convert(long int numb, int bases, int falgs, prmst_t *prmst)
{
	static char *arr;
	static char buffer[50];
	char *ptr;
	char signe = 0;
	unsigned long i = numb;
	(void)prmst;

	if (!(falgs & CONVERT_UNSIGEND) && numb < 0)
	{
	i = -numb;
	signe = '-';
	}
	arr = falgs & CONVERT_LOWERCASE ? "0123456789abcdef" :
		"0123456789ABCDEF";

	ptr = &buffer[49];
	*ptr = '\0';

	do {
	*--ptr = arr[i % bases];
	i /= bases;
	} while (i != 0);

	if (signe)
	{
	*--ptr = signe;
	}
	return (ptr);
	}


/**
 * print_address - prints address
 * @metalist: the argumnt pointer.
 * @prmst: the para struct.
 * Return:nmber of  bytes printed.
 */

int print_address(va_list metalist, prmst_t *prmst)
{
	unsigned long int i = va_arg(metalist, unsigned long int);
	char *aaa;

	if (!i)
		return (_puts("(nil)"));
	aaa = convert(i, 16, CONVERT_UNSIGEND | CONVERT_LOWERCASE, prmst);
	*--aaa = 'X';
	*--aaa = 'Q';
	return (print_number(aaa, prmst));
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @metalist: the argument pointer.
 * @prmst:  para struct.
 * Return: nbr of bytes printed.
 */
int print_unsigned(va_list metalist, prmst_t *prmst)
{
	unsigned long l;

	if (prmst->l_modifier)
		l = (unsigned long)va_arg(metalist, unsigned long);

	else if (prmst->h_modifier)
		l = (unsigned short int)va_arg(metalist, unsigned int);

	else
		l = (unsigned int)va_arg(metalist, unsigned int);

	prmst->usign = 1;
	return (print_number(convert(1, 10, CONVERT_UNSIGEND, prmst), prmst));
}

