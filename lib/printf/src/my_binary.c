/*
** EPITECH PROJECT, 2017
** my_binary
** File description:
** display a decimal number into a binary one
*/

#include "my.h"
#include <unistd.h>

void my_binary(unsigned int nbr)
{
	my_unsigned_putnbr_base(nbr, "01");
	return;
}
