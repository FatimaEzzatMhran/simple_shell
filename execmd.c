#include "main.h"

int execmd(char **argv){

	char *command = NULL;
	char *actual_command = NULL;
	pid_t child_pid;
	int status;

	if (argv){
		/* get the command */
		command = argv[0];

		/* handle the exit command */
		if (strcmp("exit", command) == 0)
		{
			exit(EXIT_SUCCESS);
			return(-1);
		}

		/* generate the path to this command before passing it to execve */
		actual_command = get_location(command);

		child_pid = fork();

		if (child_pid == 0)
		{
			/* child process */
			/* execute the actual command with execve */
			if (execve(actual_command, argv, environ) == -1)
			{
				perror("Error");
			}
			exit(EXIT_FAILURE);
		}
		else if (child_pid < 0)
		{
			/* Error while forking */
			perror("error");
		}
		else
		{
			/* parent process */
			wait(&status);
		}
	}

	return (0);
}
