/*
** EPITECH PROJECT, 2018
** display_list.c
** File description:
** display list
*/

#include "my.h"
#include <unistd.h>

void print_list(llist_t *list)
{
	llist_t *tmp = list;

	while (tmp) {
		my_putstr(tmp->str);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}
