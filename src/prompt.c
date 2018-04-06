/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** prompt
*/

#include "mysh.h"
#include "my.h"
#include <unistd.h>

void pwd(my_env_t *env)
{
	llist_t *tmp = env->env;
	int i = 0;

	while (my_strncmp(tmp->str, "PWD", 3))
		tmp = tmp->next;
	if (!tmp)
		return;
	while (tmp->str[i])
		i++;
	while (tmp->str[i] != '/' && i != 0)
		i--;
	while (tmp->str[i++])
		write(1, &tmp->str[i], 1);
}

void user(my_env_t *env)
{
	llist_t *tmp = env->env;

	while (my_strncmp(tmp->str, "LOGNAME", 7))
		tmp = tmp->next;
	if (!tmp)
		return;
	for (int i = 8; tmp->str[i]; i++)
		write(1, &tmp->str[i], 1);
}

void host(my_env_t *env)
{
	llist_t *tmp = env->env;

	while (my_strncmp(tmp->str, "HOSTNAME", 8))
		tmp = tmp->next;
	if (!tmp)
		return;
	write(1, "@", 1);
	for (int i = 9; tmp->str[i] != '.' && tmp->str[i]; i++)
		write(1, &tmp->str[i], 1);
}
