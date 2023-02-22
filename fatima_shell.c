#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "#cisfun$ ";
	char *line = NULL; /*if line (first arg of getline) is NULL, getline
			     function will allocate a buffer to store the line
			     and in this case the second arg will be ignored*/
	size_t n = 0; /* getline will automatically specify the size */
	/* on success getline return the number of chars read including
	 * the delimiter char but not including ('\0').
	 * It returns -1 on failure to read line (including end of file)
	 */
	ssize_t nchars_read; /* to read the return value of getline() */
	char *line_copy = NULL; /* cause strtok will break down the string
				   passed */
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	/* declaring void variables */
	(void)argc;

	while (1)
	{
		printf("%s", prompt);

		nchars_read = getline(&line, &n, stdin);

		if (nchars_read == -1)
		{ 	/* The function feof(FILE *stream)
           		tests the end-of-file indicator for the
           		stream pointed to by stream,
           		returning nonzero if it is set. */
            		if (feof(stdin))
			{
				exit(EXIT_SUCCESS); /* end of file */
			}
                	else
                	{
                        	perror("error in reading line");
                        	exit(EXIT_FAILURE);
                	}
        	}

		/* allocate space for a copy of the line */

		line_copy = malloc(sizeof(char) * nchars_read);
	        if (line_copy == NULL)
		{
                	perror("can't allocate memory");
                	return (-1);
		}
        	strcpy(line_copy, line);

        	/* On the first call to strtok() the string to be parsed should
	         * be specified in str. In each subsequent call that should parse
        	 * the same string, str must be NULL */
     		/* The strtok() function return a pointer to the next token OR
		 * NULL if there are no more tokens */
        	token = strtok(line, delim);

        	/* determine how many tokens are there */
		
		while (token != NULL)
		{
                	num_tokens++;
                	token = strtok(NULL, delim);
        	}
        	num_tokens++;

        	/* allocate space to hold the array of strings, the total size will
		 * be calculated by multiplying the size of charcter pointer
		 * by the total number of tokens */

        	argv = malloc(sizeof(char *) * num_tokens);
		
		/* store each token in the argv array */
		token = strtok(line_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/* execute the command */
		execmd(argv);
	}
	
	/* free allocated memory */
	free(line_copy);
	free(line);
	
	return (0);

}
