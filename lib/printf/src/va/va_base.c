/*
** EPITECH PROJECT, 2017
** va_base
** File description:
** va_arg base
*/

#include <stdarg.h>

#include "my.h"
#include "printf.h"

void va_binary(va_list list)
{
	unsigned int nbr = va_arg(list, unsigned int);

	my_binary(nbr);
}

void va_octal(va_list list)
{
	unsigned int nbr = va_arg(list, unsigned int);

	 my_octal(nbr);
}

void va_hexa(va_list list)
{
	unsigned int nbr = va_arg(list, unsigned int);

	my_hexa(nbr);
}

void va_maj_hexa(va_list list)
{
	unsigned int nbr = va_arg(list, unsigned int);

	my_maj_hexa(nbr);
}

void va_adress(va_list list)
{
	void *ptr = va_arg(list, void *);

	my_adress(ptr);
}
