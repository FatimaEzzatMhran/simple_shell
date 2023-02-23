#include "main.h"

/**
 * _help - help commande
 * @av: arguments valeur
 *
 * Return: 0
 */

int _help(char **av)
{
	if (av[2])
		write(2, "too many arguments\n", strlen("too many arguments\n"));
	if (av[1] == NULL)
		write(2, "Too few arguments\n", strlen("Too few arguments\n"));
	else
	{
		if (_strcmp("cd", av[1]) == 0)
		{
			write(1, "cd command is used for change the shell working ", strlen("cd command is used for change the shell working "));
			write(1, "directory.\n", strlen("directory.\n"));
		}
		else if (_strcmp("exit", av[1]) == 0)
			write(1, "exit command is used for exit the shell.\n", strlen("exit command is used for exit the shell.\n"));
		else if (_strcmp("echo", av[1]) == 0)
		{
			write(1, "echo command is used for write arguments to the standar ", strlen("echo command is used for write arguments to the standar "));
			write(1, "output.\n", strlen("output.\n"));
		}
		else if (_strcmp("help", av[1]) == 0)
		{
			write(1, "help command is used for display information about builtin.", strlen("help command is used for display information about builtin."));
			write(1, "commands.\n", strlen("commands.\n"));
		}
		else if (_strcmp("alias", av[1]) == 0)
		{
			write(1, "alias command is used for define or display aliases ", strlen("alias command is used for define or display aliases "));
			write(1, "commands.\n", strlen("commands.\n"));
		}
		else
			write(2, "Command not found\n", strlen("Command not found\n"));
	}
	return (0);
}
