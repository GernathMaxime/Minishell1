/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** return 1 by 1 the line of a fd
*/

#include "gnl.h"
#include <unistd.h>
#include <stdlib.h>

static char *my_reallocat(char *dest, char *src, int size, int bool)
{
	char *new;
	int i = 0;
	int len = 0;

	for (int i = 0; dest != NULL && dest[++len] != '\0'; i++);
	if ((new = malloc(sizeof(char) * (len + size + 1))) == NULL)
		return (NULL);
	if (bool == 1 && dest != NULL)
		while (dest[i] != 0) {
			new[i] = dest[i];
			i++;
		}
	for (int j = 0 ; src && j < size && src[j] != 0; j++)
		new[i++] = src[j];
	new[i] = '\0';
	free(dest);
	return (new);
}

char *line_manager(char *line, char **end, int stop)
{
	int len = 0;

	if (line == NULL && *end == NULL)
		return (NULL);
	for (int i = 0; line[++len] != '\0'; i++);
	if ((*end = my_reallocat(*end, line, len, 0)) == NULL)
		return (NULL);
	if (*end != NULL && *end[0] == 0) {
		free(*end);
		*end = NULL;
	}
	line[stop] = 0;
	return (line);
}

int scan_line(char *line)
{
	for (int i = 0; line[i] && line != NULL; i++)
		if (line[i] == '\n')
			return (i);
	return (-84);
}

char *get_next_line(int fd)
{
	static char *end;
	char *line = NULL;
	char buffer[READ_SIZE];
	int i;
	int stop;

	while ((i = read(fd, buffer, READ_SIZE)) > 0) {
		if ((line = my_reallocat(line, buffer, i, 1)) == NULL)
			return (NULL);
		if ((stop = scan_line(line)) >= 0)
			return (line_manager(line, &end, stop));
	}
	if (i <= 0 && line == NULL)
		return (NULL);
	else
		return (line);
}
