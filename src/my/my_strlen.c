/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** return the string len
*/

#include <unistd.h>

int my_strlen(char *str)
{
	int i = 0;

	if (!(str))
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
