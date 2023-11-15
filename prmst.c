#include "main.h"
/**
 * init_prmst - clear struct.
 * @prmst: parameters struct.
 * @metalist: argument param.
 * Return: nothing.
*/

void init _prmst(prmst_t *prmst, va_list metalist)
{
	(*prmst.unsign) = 0;
	prmst->plus_falg = 0;
	(*prmst.space_falg) = 0;
	prmst->minus_falg = 0;
	(*prmst.whidth) = 0;
	prmst->hashtag_falg = 0;
	(*prmst.zero_falg) = 0;
	prmst->precision = UINT_MAX;
	prmst->h_modifier = 0;
	prmst->l_modifier = 0;
	(void)metalist;
}

