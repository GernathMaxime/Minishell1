/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include <unistd.h>

char *my_strcpy(char *dest, char *src)
{
	if (!dest || !src)
		return (NULL);
	for (int i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	return (dest);
}
