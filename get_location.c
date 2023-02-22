/* this function will take the command that was passed (eg: ls)
 * and return the path of that command (eg: /usr/bin/ls)
 * This function will have a char * for the return data type and
 * the parameter/argument since both are strings
 */

/* To help us get the path for the given command, we first have to
 * access the environment variable PATH and it's value
 * PATH : a string with all the various paths that a shell searches
 *        through by default where each path is separated by a colon (:)
 *        echo $PATH , to check the PATH variable
 */

/* getenv() function: this function searches the environment list to find
 * the specific environment variable name which you pass to it as argument
 * char *getenv(const char *name);
 * returns a pointer to the value in the environment or NULL if no match
 */

#include "main.h"

char *get_location(char *command){

	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	const char *delim = ":";
	struct stat st;

	path = getenv("PATH");

	if (path)
	{
		/* Duplicate the path string (don't forget to free it) */
		path_copy = strdup(path);

		/* get the length of the command that was passed */
		command_length = strlen(command);

		/* break down the path variable and get all the directories available */
		path_token = strtok(path_copy, delim);

		while(path_token != NULL)
		{
			/* Get the length of the directory*/
            		directory_length = strlen(path_token);

            		/* allocate memory for storing the command name together with
			 * the directory name */
            		file_path = malloc(command_length + directory_length + 2);

			/* Note: added 2 for the slash and null character we will introduce
			 * in the full command */
            		/* to build the path for the command, copy the directory path and
			 * concatenate the command to it */
			/* example: ls is in /usr/bin/ls and we knew that by typing $which ls
			 *          and since PATH searches in /usr/bin > check echo $PATH
			 *          I have to concatenate the "/" and the "\0" */

            		strcpy(file_path, path_token);
            		strcat(file_path, "/");
            		strcat(file_path, command);
            		strcat(file_path, "\0");

            		/* test if this file path actually exists and return it if it
			 * does, otherwise try the next directory */
			/* stat system call (gets the status of the file
			 * int stat(const char *restrict pathname, struct stat *restrict statbuf);
			 * Return 0 in success and -1 if error occured
			 * gets status information about a specified file and places it in the
			 * area of memory pointed to by the buf argument.
			 */

            		if (stat(file_path, &st) == 0)
			{
                		/* returning 0 means success meaning that the file_path is valid */

                		/* free up allocated memory before returning your file_path */
                		free(path_copy);

                		return (file_path);
            		}
            		else
			{
                		/* free up the file_path memory so we can check for another path*/
                		free(file_path);
                		path_token = strtok(NULL, delim);
            		}
        	}

        	/* if we didn't get any file_path that exists for the command, we return NULL
		 * but we need to free up memory for path_copy */
        	free(path_copy);

        	/* before we exit without luck, check if the command itself is a file_path
		 * that exists */
        	if (stat(command, &st) == 0)
        	{
            		return (command);
        	}
        	return (NULL);
    }
    return (NULL);
}
