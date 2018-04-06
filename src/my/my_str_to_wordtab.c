/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my
*/

#include <stdlib.h>
#include "my.h"

static int my_issep(char c, char *sep)
{
	int i = 0;

	while (sep[i]) {
		if (c == sep[i])
			return (0);
		i++;
	}
	return (1);
}

static char *get_arg(char *str, char *sep, int *j)
{
	char *ret;
	int i = 0;

	if (!sep)
		return (NULL);
	while (my_issep(str[*j], sep) == 0)
		*j += 1;
	while (my_issep(str[*j + i], sep) == 1 && str[*j + i] != '\0')
		i++;
	if ((ret = my_calloc(sizeof(char *), i + 1)) == NULL)
		return (NULL);
	for (int k = 0; my_issep(str[*j], sep) == 1 && str[*j] != '\0'; k++) {
		ret[k] = str[*j];
		*j += 1;
	}
	return (ret);
}

static int get_arg_nb(char *str, char *sep)
{
	int i = 0;
	int y = 0;

	if (!sep)
		return (1);
	while (my_issep(str[y], sep) == 0 && str[y] != '\0')
		y++;
	while (str[y] != '\0') {
		if (my_issep(str[y], sep) == 1 && str[y] != '\0' &&
		(my_issep(str[y + 1], sep) == 0 || str[y + 1] == '\0'))
			i++;
		y++;
	}
	return (i);
}

char **my_str_to_world_array(char *str, char *sep)
{
	int arg_nb;
	int j = 0;
	char **array;

	if (!str)
		return (NULL);
	if (!sep) {
		array = &str;
		return (array);
	}
	arg_nb = get_arg_nb(str, sep);
	if ((array = my_calloc(sizeof(char *), arg_nb + 1)) == NULL)
		return (NULL);
	for (int y = 0; y < arg_nb; y++)
		array[y] = get_arg(str, sep, &j);
	return (array);
}
