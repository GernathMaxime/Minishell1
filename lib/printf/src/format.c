/*
** EPITECH PROJECT, 2017
** format
** File description:
** Taking care of the format
*/

#include "my.h"
#define FORMAT_L "hlLjzt"

int space_manag(int i, const char *flag)
{
	while (flag[i] == ' ')
		i++;
	return (i);
}

int ignore_f(int i, const char *flag)
{
	int comp = 0;

	if (flag[i - 1] == ' ' || flag[i] == ' ')
		my_putchar(' ');
	i = space_manag(i, flag);
	while (FORMAT_L[comp] != '\0') {
		if (FORMAT_L[comp] == flag[i]) {
			i++;
		} else
			comp++;
	}
	return (i);
}
