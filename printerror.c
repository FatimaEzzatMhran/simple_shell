#include "main.h"
/**
 * printerror - prints an error message on stderr
 *
 * @argv: name of the executable
 * @count: counter of errors
 * @av: name of the command
 */

void printerror(char **argv, int count, char **av)
{
	write(2, *argv, strlen(*argv));
	write(2, ": ", 2);
	write_integer_error(count);
	write(2, ": ", 2);
	write(2, *av, strlen(*av));
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}

/**
 * write_integer_error - print an integer with write's function on stderr
 * @number: integer
 * Return: number of characters printed
 */

int write_integer_error(int number)
{
	int temp, characters_printed = 0;
	unsigned int c1;

	if (number < 0)
	{
		number = -number;
		write(2, "-", 1);
		characters_printed++;
	}
	c1 = number;
	if (c1 / 10)
	{
		characters_printed += write_integer(c1 / 10);
	}
	temp = (c1 % 10) + '0';
	return (characters_printed += write(2, &temp, 1));
}
