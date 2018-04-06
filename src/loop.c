/*
** EPITECH PROJECT, 2018
** loop.c
** File description:
** loop
*/

#include "colors.h"
#include "mysh.h"
#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"

void prompt(my_env_t *env)
{
	my_printf("%s", KGRN);
	write(1, "༼ つ◕_◕༽つ", 20);
	my_printf("%s", KCYN);
	write(1, "[", 1);
	user(env);
	host(env);
	write(1, " ", 1);
	pwd(env);
	write(1, "]$ ", 3);
	my_printf("%s", KNRM);
}

char *get_com(my_env_t *env)
{
	char *com;
	char *new;

	if (isatty(0))
		prompt(env);
	com = get_next_line(0);
	new = clear_str(com);
	free(com);
	return (new);
}

int loop(my_env_t *env)
{
	char *line = NULL + 1;
	char **tab_com = NULL;

	while (line != NULL) {
		if ((line = get_com(env)) == NULL)
			break;
		tab_com = my_str_to_world_array(line, " ");
		if (my_preexec(tab_com, env, line) < 0)
			return (0);
	}
	return (0);
}
