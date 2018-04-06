/*
** EPITECH PROJECT, 2018
** list_len.c
** File description:
** list len
*/

#include <unistd.h>
#include "my.h"

int list_len(llist_t *list)
{
	llist_t *tmp = list;
	int i = 0;

	for (; tmp; i++)
		tmp = tmp->next;
	return (i);
}
