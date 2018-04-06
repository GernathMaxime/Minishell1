/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** my_strcat
*/

#include <unistd.h>
#include "my.h"

char *my_strcat(char *dest, char *src)
{
	char *ret;
	int i = 0;
	int y = 0;

	if (!(ret = malloc(my_strlen(dest) + my_strlen(src) + 1)))
		return (NULL);
	for (; dest[i]; i++)
		ret[i] = dest[i];
	for (; src[y]; i++, y++)
		ret[i] = src[y];
	ret[i] = '\0';
	return (ret);
}
