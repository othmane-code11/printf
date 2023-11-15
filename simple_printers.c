#include "main.h"

/**
 * print_from_to - print adr of char.
 * @strt: start of adr.
 * @stp: final of adr.
 * @exept: exept
 * Return:nmber of char printed.
 */

int print_from_to(char *strt, char *stp, char *exept)
{
	int rt = 0;

	while (strt <= stp)
	{
		if (strt != exept)
		{
			rt += _putchar(*strt);
		}
		strt++;
	}
	return (rt);
}


/**
 * print_rot13 - print str of rot13.
 * @metalist: strng .
 * @prmst: struct metalist .
 * Return:nmber of char printed.
 */

int print_rot13(va_list metalist, prmst_t *prmst)
{
	int counter = 0;
	int x = 0, index = 0;
	char aay[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijkim";
	char *a = va_arg(metalist, char *);
	(void) prmst;

	while (a[x] != ‘\0’)
	{
		if ((a[x] <= 'Z' && a[x] >= 'A') || (a[x] <= 'z' && a[x] >= 'a'))
		{
			index = a[x] - 65;
			counter += _putchar(aay[index]);
		}
		else
		{
			counter += _putchar(a[x]);
		}
		x++;
	}
	return (counter);
}


/**
 * print_rev - print adr of char.
 * @metalist: strng. .
 * @prmst: struct metalist .
 * Return:nmber of char printed.
 */
int print_rev(va_list metalist, prmst_t *prmst)
{
	int len;
	int rt = 0;
	char *aaa = va_arg(metalist, char *);
	(void)prmst;

	if (aaa)
	{
		for (len = 0; *aaa; aaa++)
			len++;
		aaa--;
		for (; len > 0; len = len - 1)
		{
			rt += _putchar(*aaa);
			aaa -= 1;
		}
	}
	return (rt);
}

