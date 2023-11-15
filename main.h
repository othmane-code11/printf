#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH  -1
#define NULL_STRING "(null)"
#define PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGEND 2

/**
 * struct parametre - parametre struct
 * @unsign: flag if unsigned value
 * @space_falg: on if hashtag _flag specifer
 * @plus_falg: on if plus_flage specifed
 * @hashtag_falg: on if _flage specifed
 * @zero_falg: on if _flage specifed
 * @minus_falg: on if _flage specifed
 * @whidth: fieled witdh specifed
 * @precision: fieled precision specifed
 *
 * @h_modifer: on if h_modifer is specifed
 * @l_modifer: on if l_modifer is specifed
*/
typedef struct parametre
{
	unsigned int unsign		: 1;
	unsigned int plus_falg		: 1;
	unsigned int space_falg		: 1;
	unsigned int hashtag_falg	: 1;
	unsigned int zero_falg		: 1;
	unsigned int minus_falg		: 1;
	unsigned int h_modifer		: 1;
	unsigned int l_modifer		: 1;
	unsigned int whidth;
	unsigned int precision;
} prmst_t;
/**
 * struct specifer -struct token
 * @specifer: format token
 * @f: function associated
*/

typedef struct specifer
{
	char *specifer;
	int (*f)(va_list, prmst_t *);
} specifer_t;

int _puts(char *aaa);
int _puts(int ch);
int print_char(va_list metalist, prmst_t *prmst);
int print_int(va_list metalist, prmst_t *prmst);
int print_string(va_list metalist, prmst_t *prmst);
int print_percent(va_list metalist, prmst_t *prmst);
int print_S(va_list metalist, prmst_t *prmst);
char *convert(long int numb, int bases, int falgs, prmst);
int print_unsigned(va_list metalist, prmst_t *prmst);
int print_address(va_list metalist, prmst_t *prmst);
int (*get_specifer(char *sp))(va_list metalist, prmst_t *prmst);
int get_print_func(char *sp, va_list metalist, prmst_t *prmst);
int get_falg(char *sp, prmst_t *prmst);
int get_modifier(char *sp, prmst_t *prmst);
char *get_whidht(char *sp, prmst_t *prmst, va_list metalist);
int print_hex(va_list metalist, prmst_t *prmst);
int print_HEX(va_list metalist, prmst_t *prmst);
int print_binary(va_list metalist, prmst_t *prmst);
int print_octal(va_list metalist, prmst_t *prmst);
int print_from_to(char *strt, char *stp, char *exept);
int print_rev(va_list metalist, prmst_t *prmst);
int print_rot13(va_list metalist, prmst_t *prmst);
int _isdigit(int ch);
int _strlen(char *sp);
int print_number(char *aaa, prmst_t *prmst);
int print_number_right_shift(char *aaa, prmst_t *prmst);
int print_number_left_shift(char *aaa, prmst_t *prmst);
void init_prmst(prmst_t *prmst, va_list metalist);
char *get_precision(char *ptrn, prmst_t *prmst, va_list metalist);
int _printf(const char *format, ...);
#endif
