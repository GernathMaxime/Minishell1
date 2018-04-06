/*
** EPITECH PROJECT, 2017
** base
** File description:
** base
*/

#include <unistd.h>

#include "my.h"

int my_putnbr_base(int nbr, const char *base)
{
	int size;
	int res;
	int rest;

	if (base == NULL)
		return (-1);
	size = my_strlen(base);
	if (nbr < 0) {
		my_putchar('-');
		nbr = -nbr;
	}
	res = nbr / size;
	rest = nbr % size;
	if (res > 0)
		my_putnbr_base(res, base);
	my_putchar(base[rest]);
	return (nbr);
}

void my_long_putnbr_base(void *nb, const char *base)
{
	int i = 0;
	long nbr = (long)nb;
	int size = my_strlen(base);
	char str[size];
	long res;

	if (nbr < 0) {
		my_putchar('-');
		nbr = -nbr;
	}
	while (nbr > 0) {
		res = nbr % size;
		str[i] = base[res];
		nbr = nbr / size;
		i++;
	}
	str[i] = '\0';
	my_revstr(str);
	my_putstr(str);
}

unsigned int my_unsigned_putnbr_base(unsigned int nbr, const char *base)
{
	unsigned int size;
	unsigned int res;
	unsigned int rest;

	if (base == NULL)
		return (-1);
	size = my_strlen(base);
	res = nbr / size;
	rest = nbr % size;
	if (res > 0)
		my_unsigned_putnbr_base(res, base);
	my_putchar(base[rest]);
	return (nbr);
}
