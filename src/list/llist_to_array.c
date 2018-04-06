/*
** EPITECH PROJECT, 2018
** llist_to_array.c
** File description:
** list to array
*/

#include <stdlib.h>
#include "my.h"

char **llist_to_array(llist_t *list)
{
	llist_t *tmp;
	char **array;

	if (!list || !(array = my_calloc(sizeof(char *), (list_len(list) + 1))))
		return (NULL);
	tmp = list;
	for (int i = 0; tmp != NULL; i++) {
		if (!(array[i] = my_strdup(tmp->str)))
			return (NULL);
		tmp = tmp->next;
	}
	return (array);
}
