/*
** EPITECH PROJECT, 2018
** find_path.c
** File description:
** find path
*/

#include "my.h"
#include "mysh.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int my_strnlen(char *str, int n)
{
	int len = 0;

	if (!(str) || n > my_strlen(str))
		return (0);
	for (; str[n] != '\0'; n++)
		len++;
	return (len);
}

static int char_find(char *str, char c)
{
	for (int i = 0; str[i] && str[i] != ' '; i++)
		if (str[i] == c)
			return (1);
	return (0);
}

char *get_path(char **ev)
{
	int i = 0;
	char *pa;

	if (!ev)
		return (NULL);
	while ((my_strncmp(ev[++i], "PATH=", 5) != 0) && ev[i]);
	if (!(pa = my_calloc(sizeof(char), (my_strnlen(ev[i], 5) + 2))))
		return (NULL);
	for (int j = 0; ev[i][j + 5]; j++)
		pa[j] = ev[i][j + 5];
	return (pa);
}

char *take_path(char *av)
{
	int i = 0;
	char *path;

	for (; av[i] != ' ' && av[i]; i++);
	path = my_calloc(sizeof(char), i + 1);
	i = 0;
	for (; av[i] != ' ' && av[i]; i++)
		path[i] = av[i];

	return (path);
}

char *find_path(char *cmd, char **env, char *av)
{
	char *path = get_path(env);
	char **tab = NULL;
	char *tmp;

	if (!cmd || !path)
		return (NULL);
	if (char_find(av, '/') == 1)
		return (take_path(av));
	if (!(tab = parse_path(path)))
		return (NULL);
	for (int i = 0; tab && tab[i]; i++) {
		tmp = tab[i];
		if (tmp[my_strlen(tmp) - 1] != '/')
			if ((tmp = my_strcat(tmp, "/")) == NULL)
				return (NULL);
		if (access(my_strcat(tmp, cmd), X_OK) == 0)
			return (my_strcat(tmp, cmd));
	}
	return (NULL);
}
