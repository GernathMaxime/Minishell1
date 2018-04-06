/*
** EPITECH PROJECT, 2017
** my_octal
** File description:
** print a number into ocatal base
*/

#include "my.h"
#include <unistd.h>

void my_octal(unsigned int nbr)
{
	my_unsigned_putnbr_base(nbr, "01234567");
	return;
}
