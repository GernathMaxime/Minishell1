/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Print str char int depending of the flag argument
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "printf.h"
#define FLAGS_L "diboxXucsSphlLjzt"

int check_flag(char flag)
{
	int i = 0;

	while (FLAGS_L[i] != '\0') {
		if (FLAGS_L[i] == flag)
			return (0);
		else
			i++;
	}
	return (1);
}

void tab_create(void (**tab)())
{
	tab[0] = va_put_nbr;
	tab[1] = va_put_nbr;
	tab[2] = va_binary;
	tab[3] = va_octal;
	tab[4] = va_hexa;
	tab[5] = va_maj_hexa;
	tab[6] = va_put_unsigned_nbr;
	tab[7] = va_putchar;
	tab[8] = va_putstr;
	tab[9] = va_unprintable;
	tab[10] = va_adress;
}

int find_flag(const char *flag, int i, va_list list, void (**tab)())
{
	int comp = 0;
	int sav_pos = i - 1;

	i = space_manag(i, flag);
	if (flag[i] == '%') {
		my_putchar('%');
		return (i);
	}
	if (check_flag(flag[i]) == 0) {
		i = ignore_f(i, flag);
		while (FLAGS_L[comp] != flag[i])
			comp++;
		tab[comp](list);
		return (i);
	}
	while (sav_pos <= i) {
		sav_pos = ignore_f(sav_pos, flag);
		my_putchar(flag[sav_pos++]);
	}
	return (sav_pos - 1);
}

void my_printf(const char *format, ...)
{
	ptr_fonction_t buffer;
	int i = 0;

	if (format == NULL)
		return;
	tab_create(buffer.tab);
	va_start(buffer.list, format);
	while (format[i] != '\0') {
		if (format[i] == '%')
			i = find_flag(format, i + 1, buffer.list, buffer.tab);
		else
			my_putchar(format[i]);
		i++;
	}
	va_end(buffer.list);
	return;
}
