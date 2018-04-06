/*
** EPITECH PROJECT, 2017
** show_unprintable
** File description:
** replace unprintable char by //
*/

#include "my.h"
#include "printf.h"

void show_unprintable(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] > 32 && str[i] < 127)
			my_putchar(str[i]);
		else
			my_putchar('\\');
		i++;
	}
	return;
}
