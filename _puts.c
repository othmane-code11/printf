#include "main.h"
/**
 * _puts - print a string with a new_line \n.
 * @aaa:  string to be printed .
 *
 * Return: aaa - a.
 */

int _puts(char *aaa)
{
	char *a;

	a = aaa;
	while (*aaa)
	{
		_putchar(*aaa);
		aaa++;
	}
	return (aaa - a);
}
/**
 * _putchar - print or write the character ch.
 * @ch: the char to be printed.
 *
 * Return: on success (1), on error (-1).
 */

int _putchar(int ch)
{
	static char buf[OUTPUT_BUF_SIZE];
	static int x;

	if (x >= OUTPUT_BUF_SIZE || ch == BUF_FLUSH)
	{
		write(1, buf, x);
		x++;
	}
	else if (ch != BUF_FLUSH)
		buf[x++] = ch;

return (1);
}

