/*
** EPITECH PROJECT, 2017
** printf
** File description:
** proto prinft
*/

#include <stdarg.h>
#ifndef PRINTF_H_
# define PRINTF_H_

struct ptr_fonction_s
{
	va_list list;
	void  (* tab[11])(va_list list);
};
typedef struct ptr_fonction_s ptr_fonction_t;

int ignore_f(int i, const char *flag);
int space_manag(int i, const char *flag);
void my_put_unsigned_nbr(unsigned int nb);
void my_binary(unsigned int nbr);
void my_octal(unsigned int nbr);
void my_hexa(unsigned int nbr);
void my_maj_hexa(unsigned int nbr);
void my_long_hexa(void *nbr);
void my_printf(const char *format, ...);
void my_adress(void *ptr);
void show_unprintable(char *str);
void va_putchar(va_list list);
void va_putstr(va_list list);
void va_put_nbr(va_list list);
void va_put_unsigned_nbr(va_list list);
void va_binary(va_list list);
void va_octal(va_list list);
void va_hexa(va_list list);
void va_maj_hexa(va_list list);
void va_adress(va_list list);
void va_unprintable(va_list list);

#endif /* !PRINTF_H_ */
