/*
** EPITECH PROJECT, 2018
** parse_path.c
** File description:
** parse path
*/

#include <my.h>

static int get_arg_nb(char *line, int j)
{
	int nbr = 0;

	while (line[j]) {
		if (line[j] == ':')
			nbr++;
		j++;
	}
	return (nbr);
}

static int arg_len(char *av, int ptr)
{
	int len = 0;

	if (!av)
		return (0);
	for (int i = ptr; av[i] != '\0' && av[i] != ':'; i++, len++);
	return (len);
}

char **parse_path(char *av)
{
	int j = 0;
	int nb_arg = get_arg_nb(av, j);
	char **tmp;

	if ((tmp = my_calloc(sizeof(char *), (nb_arg + 2))) == NULL)
		return (NULL);
	for (int count = 0; count < nb_arg + 1; count++) {
		tmp[count] = my_calloc(sizeof(char), arg_len(av, j) + 1);
		for (int i = 0; av[j] != ':' && av[j]; i++) {
			tmp[count][i] = av[j];
			j++;
		}
		j++;
	}
	return (tmp);
}
