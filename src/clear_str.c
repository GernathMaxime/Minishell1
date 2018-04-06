/*
** EPITECH PROJECT, 2018
** clean_str
** File description:
** clear_str
*/

#include <stdlib.h>
#include "my.h"

static int slen(char *av)
{
	int len = 0;
	int i = 0;
	int count = 0;

	if (!(av))
		return (0);
	while (av[i] != '\0') {
		while ((av[i] == ' ' || av[i] == '\t') && av[i] != '\0')
			i++;
		if (count != 0 && av[i] != '\0')
			len++;
		while (av[i] != ' ' && av[i] != '\0' && av[i] != '\t') {
			len++;
			i++;
		}
		count++;
	}
	return (len);
}

char *clear_str(char *str)
{
	int count = 0;
	int len = slen(str);
	char *new = my_calloc(sizeof(char), (len + 2));
	int j = 0;

	if (!(new) || !(str))
		return (NULL);
	for (int i = 0; str[i] != '\0'; count++) {
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (count != 0 && str[i])
			new[j++] = ' ';
		for (; str[i] != ' ' && str[i] && str[i] != '\t'; i++)
			new[j++] = str[i];
	}
	new[len] = '\0';
	return (new);
}
