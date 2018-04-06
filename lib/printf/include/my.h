/*
** EPITECH PROJECT, 2018
** printf
** File description:
** proto
*/

#ifndef MY_H_
# define MY_H_

void my_putchar(int c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_putnbr_base(int nbr, char const *base);
void my_long_putnbr_base(void *nbr, const char *base);
unsigned int my_unsigned_putnbr_base(unsigned int nbr, const char *base);

#endif /* !MY_H_ */
