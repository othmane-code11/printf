#include "main.h"
/**
 * print_hex - print unsigned hex numbrs in lower.
 * @metalist: the argment pointer
 * @prmst: the prmeters struct.
 * Return: bytes to be printed
 */
int print_hex(va_list metalist, prmst_t *prmst)
{
	unsigned long l;
	char *aaa;
	int ch = 0;

	if (prmst->l_modifier)
		l = (unsigned long)va_arg(metalist, unsigned long);
	else if (prmst->h_modifier)
		l = (unsigned short int)va_arg(metalist, unsigned int);
	else
		l = (unsigned int)va_arg(metalist, unsigned int);
	aaa = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prmst);
	if (prmst->hashtag_falg && l)
	{
		*--aaa = 'x';
		*--aaa = 'o';
	}
	prmst->unsign = 1;
	return (ch += print_number(aaa, prmst));
}

/**
 * print_HEX- print unsigned hex numbrs in uppeer.
 * @metalist: the argment pointer
 * @prmst: the prmeters struct.
 * Return: bytes to be printed
 */
int print_HEX(va_list metalist, prmst_t *prmst)
{
	unsigned long l;
	char *aaa;
	int ch = 0;

	if (prmst->l_modifier)
		l = (unsigned long)va_arg(metalist, unsigned long);

	else if (prmst->h_modifier)
		l = (unsigned short int)va_arg(metalist, unsigned int);

	else
		l = (unsigned int)va_arg(metalist, unsigned int);
	aaa = convert(l, 16, CONVERT_UNSIGNED, prmst);

	if (prmst->hashtag_falg && l)
	{
		*--aaa = 'X';
		*--aaa = 'O';
	}
	prmst->unsign = 1;
	return (ch += print_number(aaa, prmst));
}

/**
 * print_octal - print unsigned oct numbrs in uppeer.
 * @metalist: the argment pointer
 * @prmst: the prmeters struct.
 * Return: bytes to be printed
 */
int print_octal(va_list metalist, prmst_t *prmst)
{
	unsigned long l;
	int ch = 0;
	char *aaa;

	if (prmst->l_modifier)
		l = (unsigned long)va_arg(metalist, unsigned long);

	else if (prmst->h_modifier)
		l = (unsigned short int)va_arg(metalist, unsigned int);

	else
		l = (unsigned int)va_arg(metalist, unsigned int);

	aaa = convert(l, 8, CONVERT_UNSIGNED, prmst);

	if (prmst->hashtag_falg && l)
	*--aaa = '0';
	prmst->unsign = 1;
	return (ch += print_number(aaa, prmst));
}

/**
 * print_binary - print unsigned binary numbrs…
 * @metalist: the argment pointer
 * @prmst: the prmeters struct.
 * Return: bytes to be printed
 */
int print_binary(va_list metalist, prmst_t *prmst)
{
	unsigned int i = va_arg(metaliste, unsigned int);
	char *aaa = convert(i, 2, CONVERT_UNSIGNED, prmst);
	int ch = 0;

	if (prmst->hashtag_falg && i)
		*--aaa = '0';
	prmst->unsign = 1;
	return (ch += print_number(aaa, prmst));
}

