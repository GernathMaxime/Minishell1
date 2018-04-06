/*
** EPITECH PROJECT, 2018
** get_envar.c
** File description:
** get envar
*/

#include "my.h"
#include <unistd.h>

char *get_envar(llist_t *list, char *str)
{
	int i = 0;
	char *pa;
	char **ev = llist_to_array(list);
	int len = my_strlen(str);

	if (!ev)
		return (NULL);
	while ((my_strncmp(ev[++i], str, len) != 0) && ev[i]);
	if (!(pa = my_calloc(sizeof(char), (my_strnlen(ev[i], len) + 2))))
		return (NULL);
	for (int j = 0; ev[i][j + len]; j++)
		pa[j] = ev[i][j + len];
	return (pa);
}
