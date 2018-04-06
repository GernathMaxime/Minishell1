/*
** EPITECH PROJECT, 2018
** my_exec.c
** File description:
** exec command
*/

#include "mysh.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

static void error(int signal, int status, int *sreturn)
{
	signal = WTERMSIG(status);
	*sreturn = WEXITSTATUS(status);
	*sreturn = signal + 128;
	if (signal == SIGSEGV)
		my_putstr("Segmentation fault");
	if (signal == SIGABRT)
		my_putstr("Aborted");
	if (signal == SIGFPE)
		my_putstr("Floating exception");
	if (WCOREDUMP(status))
		my_putstr(" (core dumped)");
	write(1, "\n", 1);
}

int print_error(void)
{
	int status = 0;
	int signal = 0;
	int sreturn = 0;

	wait(&status);
	if (WIFSIGNALED(status)) {
		error(signal, status, &sreturn);
		return (sreturn);
	}
	return (0);
}

int exec(char **cmd, my_env_t *env, char *line)
{
	char **envarray;
	char *path;

	if (!env)
		return (0);
	envarray = llist_to_array(env->env);
	path = find_path(cmd[0], envarray, line);
	if (access(path, F_OK) == -1)
		my_printf("%s: Command not found.\n", cmd[0]);
	execve(path, cmd, envarray);
	return (0);
}

int my_preexec(char **cmd, my_env_t *env, char *line)
{
	int builtins = 0;

	if (!cmd || !line)
		return (0);
	builtins = check_builtins(env, cmd);
	if (builtins == -1)
		return (-1);
	if (builtins == 1)
		return (0);
	if (fork() == 0) {
		exec(cmd, env, line);
		exit(0);
	}
	env->sreturn = print_error();
	return (0);
}
