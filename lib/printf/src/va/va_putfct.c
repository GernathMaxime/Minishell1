/*
** EPITECH PROJECT, 2017
** va_putfct
** File description:
** printf
*/

#include <stdarg.h>

#include "my.h"
#include "printf.h"

void va_putchar(va_list list)
{
	int c;

	c = va_arg(list, int);
	my_putchar(c);
}

void va_putstr(va_list list)
{
	const char *str;

	str = va_arg(list, const char *);
	my_putstr(str);
}

void va_put_nbr(va_list list)
{
	int nb = va_arg(list, int);

	my_put_nbr(nb);
}

void va_put_unsigned_nbr(va_list list)
{
	unsigned int nbr = va_arg(list, unsigned int);

	my_put_unsigned_nbr(nbr);
}

void va_unprintable(va_list list)
{
	char *str = va_arg(list, char *);

	show_unprintable(str);
}
