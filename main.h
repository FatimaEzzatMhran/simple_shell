#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
extern char **environ; /* It is best practice to declare all the extern variables
                          and functions in the header part of the program. */

int execmd(char **argv);
char *get_location(char *command);

#endif /* MAIN_H */
