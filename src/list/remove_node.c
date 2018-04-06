/*
** EPITECH PROJECT, 2018
** remove_node.c
** File description:
** remove node
*/

#include "my.h"

int remove_node(llist_t **list, llist_t *node)
{
	llist_t *tmp;

	if (*list == node) {
		*list = (*list)->next;
		return (1);
	}
	tmp = *list;
	while (tmp && tmp->next != node)
		tmp = tmp->next;
	if (!tmp)
		return (0);
	tmp->next = node->next;
	if (node)
		free(node);
	return (1);
}
