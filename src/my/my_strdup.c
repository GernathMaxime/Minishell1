/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *src)
{
	char *dest;
	int len = my_strlen(src);

	if (!src)
		return (NULL);
	if ((dest = my_calloc(sizeof(char *), len + 1)) == NULL)
		return (NULL);
	my_strcpy(dest, src);
	return (dest);
}
