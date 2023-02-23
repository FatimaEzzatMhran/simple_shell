#include "main.h"

/**
  * _prints - Handling the %s format of printf
  * @arg: Current arg.
  *
  * Return: Full string
  */

int _prints(va_list arg)
{
	int i;
	char *str = va_arg(arg, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

/**
  * _printS - Handling the %S format of printf
  * @arg: Current arg.
  *
  * Return: Full string
  */

int _printS(va_list arg)
{
	int i, count = 0;
	char *str = va_arg(arg, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			write(1, &str[i], 1);
			count++;
		}
		else
		{
			write(1, "\\", 1);
			write(1, "x", 1);
			count += 2;
			if (str[i] < 16)
			{
				write(1, "0", 1);
				count++;
			}
			count += write_X(str[i]);
		}
		i++;
	}
	return (count);
}
/**
 * _printc - print a character
 * @arglist: list of arguments
 * Return: number of character printed
 */
int _printc(va_list arglist)
{
	int c = va_arg(arglist, int);

	return (write(1, &c, 1));
}
