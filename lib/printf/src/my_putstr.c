/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** return the len of the string
*/

#include <unistd.h>

static int my_putstrlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

void my_putstr(char const *str)
{
	if (str == NULL) {
		write(1, "(null)", 6);
	}
	write(1, str, my_putstrlen(str));
}
