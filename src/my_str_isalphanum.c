/*
** EPITECH PROJECT, 2018
** my_str_isalphanum.c
** File description:
** my str is alphanum
*/

int alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
	(c >= '0' && c <= '9') || c == '_')
		return (1);
	return (0);
}

int my_stris_alphanum(char *str)
{
	if (!str)
		return (0);
	for (int i = 0; str[i] != 0; i++) {
		if (alphanum(str[i]) == 0)
			return (0);
	}
	return (1);
}
