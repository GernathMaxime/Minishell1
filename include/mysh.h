/*
** EPITECH PROJECT, 2018
** my_sh.h
** File description:
** struct
*/

#include "my.h"
#ifndef MY_SH_H_
# define MY_SH_H_

char *clear_str(char *str);
char *find_path(char *cmd, char **env, char *av);
int loop(my_env_t *env);
int my_preexec(char **cmd, my_env_t *env, char *line);
char **parse_path(char *av);
//void print_error(int sreturn);
int check_builtins(my_env_t *env, char **cmd);
int my_stris_alphanum(char *str);
void pwd(my_env_t *env);
void user(my_env_t *env);
void host(my_env_t *env);
void prompt(my_env_t *env);

#endif /* !MY_SH_H */
