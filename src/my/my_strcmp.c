/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include <unistd.h>

int my_strncmp(char const *s1, char const *s2, int j)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] - s2[i] == 0 && s1[i] && s2[i] && i < j)
		i++;
	if ((s1[i] == '\0' && s2[i] == '\0') || i == j)
		return (0);
	return (s1[i] - s2[i]);
}

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] - s2[i] == 0 && s1[i] != '\0' &&  s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
