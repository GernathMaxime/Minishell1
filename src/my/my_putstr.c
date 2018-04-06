/*
** EPITECH PROJECT, 2018
** lib
** File description:
** putstr
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

int my_putstr(char const *str)
{
	if (str == NULL) {
		write(1, "NULL", 4);
		return (-1);
	}
	return (write(1, str, my_putstrlen(str)));
}
