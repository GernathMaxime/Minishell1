/*
** EPITECH PROJECT, 2018
** printf
** File description:
** my_revstr
*/

#include<unistd.h>

char *my_revstr(char *str)
{
	int i = 0;
	int len = 0;
	char swap;

	if (str == NULL)
		return (str);
	while (str[len] != '\0')
		++len;
	while (i < len / 2) {
		swap = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = swap;
		i++;
	}
	return(str);
}
