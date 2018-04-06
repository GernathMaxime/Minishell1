/*
** EPITECH PROJECT, 2018

** builtins.c
** File description:
** builtins
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#define SETENV "setenv: Variable name must contain alphanumeric charaters.\n"

int my_unsetenv(llist_t **env, char *av)
{
	llist_t *tmp;
	char *copy;

	if (!av || !(copy = my_strcat(av, "=")))
		return (0);
	tmp = *env;
	while (tmp && my_strncmp(tmp->str, copy, my_strlen(copy)) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (0);
	remove_node(env, tmp);
	return (0);
}

int my_setenv(llist_t **env, char *str, char *var)
{
	char *final;
	llist_t *tmp = *env;

	if (str == NULL)
		print_list(*env);
	var = (var == NULL ? "" : var);
	if (str == NULL || !(final = my_strcat(str, "=")))
		return (0);
	if (my_stris_alphanum(str) == 0) {
		my_printf(SETENV);
		return (0);
	}
	while (tmp && my_strncmp(tmp->str, final, my_strlen(final)) != 0)
		tmp = tmp->next;
	if (tmp == NULL) {
		if (!(add_in_list(env, my_strcat(final, var))))
			return (0);
	} else
		tmp->str = my_strcat(final, var);
	return (0);
}

int my_cd(llist_t **env, char *cmd)
{
	char *new_path;
	char *old_path;

	if (cmd == NULL)
		new_path = get_envar(*env, "HOME=");
	else if (cmd[0] == '-' && cmd[1] == '\0')
		new_path = get_envar(*env, "OLDPWD=");
	else
		new_path = (cmd[0] != '~') ? cmd : get_envar(*env, "HOME=");
	old_path = getcwd(NULL, 0);
	if (chdir(new_path) == -1) {
		write(2, new_path, my_strlen(new_path));
		write(2, ": Not a directory.\n", 19);
		return (0);
	} else {
		my_setenv(env, "OLDPWD", old_path);
		my_setenv(env, "PWD", getcwd(NULL, 0));
	}
	return (0);
}

int builtins(my_env_t *env, char **cmd)
{
	if (my_strcmp(cmd[0], "exit") == 0) {
		my_putstr("exit\n");
		return (-1);
	}
	if (my_strcmp(cmd[0], "env") == 0)
		print_list(env->env);
	else if (my_strcmp(cmd[0], "unsetenv") == 0)
		my_unsetenv(&(env)->env, cmd[1]);
	else if (my_strcmp(cmd[0], "cd") == 0)
		my_cd(&(env)->env, cmd[1]);
	else if (my_strcmp(cmd[0], "setenv") == 0) {
		my_setenv(&(env)->env, cmd[1], cmd[2]);
	} else
		return (1);
	return (0);
}

int check_builtins(my_env_t *env, char **cmd)
{
	int check = (builtins(env, cmd));

	if (check == -1)
		return (-1);
	else if (check == 0)
		return (1);
	return (0);
}
