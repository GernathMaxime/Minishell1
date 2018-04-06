/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include<stdlib.h>
#ifndef MY_H_
# define MY_H_
#define my_printf my_printf

typedef struct llist_s
{
	char *str;
	struct llist_s *next;
}llist_t;

typedef struct my_env_s
{
	struct llist_s *env;
	int sreturn;
}my_env_t;

void my_printf(const char *format, ...);
char *my_strcat(char *dest, char *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int j);
int my_strlen(char *str);
void *my_calloc(size_t nmemb, size_t size);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *src);
int list_len(llist_t *list);
void print_list(llist_t *list);
char **llist_to_array(llist_t *list);
int remove_node(llist_t **list, llist_t *node);
llist_t *array_to_llist(char **array);
llist_t *add_in_list(llist_t **list, char *var);
char *get_envar(llist_t *list, char *str);
int my_strnlen(char *str, int n);
char **my_str_to_world_array(char *str, char *sep);

#endif /* !MY_H */
