#include "main.h"

/**
 * _isdigit - verify if it’s digit or not.
 * @ch: the char to verify.
 * Return: success 1 , fail 0.
 */
int _isdigit(int ch)
{
	return (ch <= '9' && ch >= '0');
}

/**
 * _strlen - len of the string.
 * @sp: the string.
 * Return: int len.
 */
int _strlen(char *sp)
{
	int x = 0;

	while (*sp)
	{
		x++;
		sp++;
	}
	return (x);
}
/**
 * print_number - write the numbr..
 * @aaa: string.
 * @prmst: prmst.
 * Return: characters printd
 */
int print_number(char *aaa, prmst_t *prmst)
{
	unsigned int x = _strlen(aaa);
	int nega = (*aaa == '-' && !prmst->unsign);

	if (!prmst->precision && !aaa[1] && *aaa == '0')
		aaa = "";
	if (nega)
	{
		aaa++;
		x--;
	}

	if (prmst->precision != UINT_MAX)
	while (x++ < prmst->precision)
		*--aaa = '0';
	if (nega)
		*--aaa = '-';
	if (!prmst->minus_falg)
	{
		return (printf_number_right_shift(aaa, prmst));
	}
	else
		return (printf_number_left_shift(aaa, prmst));
}

/**
 *print_number_right_shift - prints a number right.
 *@aaa: string .
 *@prmst: the parameter struct.
 *@print_number_right_shift - print_number_right_shift.
 *Return: charactrs printed.
*/

int print_number_right_shift(char *aaa, prmst_t *prmst)
{
	char papachar = ' ';
	unsigned int i = 0, nega, x = _strlen(aaa), nega2;

	if (prmst->zero_falg && !prmst->minus_falg)
		papachar = '0';

	nega = nega2 = (!prmst->unsign && *aaa == '-');
	if (nega && x < prmst->whidth && papachar == '0' && !prmst->minus_falg)
		aaa++;
	else
		nega = 0;

	if ((prmst->plus_falg && !nega2) ||
		(!prmst->plus_falg && prmst->space_falg && !nega2))
		x++;

	if (nega && papachar == '0')
		i += _putchar('-');

	if (prmst->plus_falg && !nega2 && papachar == '0' && !prmst->unsign)
		i += _putchar('+');
	else if (!prmst->plus_falg && prmst->space_falg && !nega2 &&
		!prmst->unsign && prmst->zero_falg)
		i += _putchar(' ');
	while (x++ < prmst->whidth)
		i += _putchar(papachar);
	if (nega && papachar == ' ')
		i += _putchar('-');
	if (prmst->plus_falg && !nega && papachar == ' ' && !prmst->unsign)
		i += _putchar('+');
	else if (!prmst->plus_falg && prmst->space_falg && !nega2 &&
		!prmst->unsign && !prmst->zero_falg)
		i += _putchar(' ');
		i += _puts(aaa);
	return (i);
}

/**
 * print_number_left_shift - write the numbr lest..
 * @aaa: string.
 * @prmst: prmst.
 * Return: characters printd
 */
int print_number_left_shift(char *aaa, prmst_t *prmst)
{
	unsigned int i = 0, nega, x = _strlen(aaa), nega2;
	char  papachar = ' ';

	if (prmst->zero_falg && !prmst->minus_falg)
		papachar = '0';
	nega = nega2 = (!prmst->unsign && *aaa == '-');

	if (nega && x < prmst->whidth && papachar == '0' && !prms->minus_falg)
		aaa++;
	else
		nega = 0;

	if (prmst->plus_falg && !nega2 && !prmst->unsign)
		i += _putchar('+'), x++;

	if (prmst->plus_falg && !nega2 && !prmst->unsign)
		i += _putchar('+'), x++;
	else if (prmst->space_falg && !nega2 && !prmst->unsign)
		i += _putchar('-'), x++;
	i += _puts(aaa);
	while (i++ < prmst->space_falg && !nega2 && !prmst->unsign)
		i += _putchar(papachar);
	return (i);
}
