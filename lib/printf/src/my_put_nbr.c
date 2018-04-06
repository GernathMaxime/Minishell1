/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** Display number
*/

#include <unistd.h>
#include "my.h"

void my_put_nbr(int nb)
{
	if (nb == -2147483648) {
		my_putstr("-2147483648");
		return;
	}
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	} else if (nb / 10 != 0) {
		my_put_nbr(nb / 10);
	}
	my_putchar(nb % 10 + 48);
	return;
}

void my_put_unsigned_nbr(unsigned int nb)
{
	if (nb / 10 != 0)
		my_put_unsigned_nbr(nb / 10);
	my_putchar(nb % 10 + 48);
	return;
}
