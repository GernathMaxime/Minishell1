/*
** EPITECH PROJECT, 2017
** my_adress
** File description:
** showing adress in hexa
*/

#include <unistd.h>
#include "my.h"
#include "printf.h"

void my_adress(void *ptr)
{
	if (ptr == NULL) {
		write(1, "(nil)", 5);
		return;
	}
	my_putstr("0x");
	my_long_hexa(ptr);
	return;
}
