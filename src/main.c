/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "mysh.h"
#include "my.h"
#include <signal.h>

void sig_handler(int sig)
{
	if (sig == SIGINT) {
		my_printf("\n");
	}
}

int main_loop(my_env_t *envp)
{
	if (loop(envp) == 84)
		return (84);
	return (0);
}

int main(int ac, char **av, char **envp)
{
	my_env_t my_env;

	if (envp[0] == NULL)
		return (84);
	my_env.env = array_to_llist(envp);
	my_env.sreturn = 0;
	signal(SIGINT, sig_handler);
	if (main_loop(&my_env) == 84)
		return (84);
	return (my_env.sreturn);
}
