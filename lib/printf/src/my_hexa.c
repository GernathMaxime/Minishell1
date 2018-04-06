/*
** EPITECH PROJECT, 2017
** my_hexa
** File description:
** print a number into a hexa base
*/

#include "my.h"
#include <unistd.h>

void my_hexa(unsigned int nbr)
{
	my_unsigned_putnbr_base(nbr, "0123456789abcdef");
	return;
}

void my_maj_hexa(unsigned int nbr)
{
	my_unsigned_putnbr_base(nbr, "0123456789ABCDEF");
	return;
}

void my_long_hexa(void *nbr)
{
	my_long_putnbr_base(nbr, "0123456789abcdef");
	return;
}
