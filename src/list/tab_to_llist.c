/*
** EPITECH PROJECT, 2018
** array_to_llist.c
** File description:
** array to linked list
*/

#include <unistd.h>
#include "my.h"
#include "mysh.h"

llist_t *add_in_list(llist_t **list, char *var)
{
	llist_t *node;
	llist_t *tmp;

	node = malloc(sizeof(*node));
	node->str = my_strdup(var);
	if (!list || !var || !node || !(node->str))
		return (NULL);
	node->next = NULL;
	if (!(*list))
		*list = node;
	else {
		tmp = *list;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (node);
}

llist_t *array_to_llist(char **array)
{
	llist_t *list;

	if (array == NULL)
		return (NULL);
	list = NULL;
	for (int i = 0; array[i]; i++)
		add_in_list(&list, array[i]);
	return (list);
}
