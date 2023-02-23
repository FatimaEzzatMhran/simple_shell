#include "main.h"

/**
  * checkSpecifier - Check the specifier after the '%' character
  * @format: format string
  * @i: index of the string
  * @arglist: current argument
  *
  * Description: It checks the specifier and then call the function associated
  * to it.
  *
  * Return: Number of characters printed to stdout
  */

int checkSpecifier(const char *format, int i, va_list arglist)
{
	int count = 0;

	if (get_specifier_func(format[i + 1]))
	{
		count += get_specifier_func(format[i + 1])(arglist);
		i++;
	}
	else if (format[i + 1] == '%')
	{
		write(1, &format[i + 1], 1);
		count++, i++;
	}
	else
	{
		write(1, &format[i], 1);
		write(1, &format[i + 1], 1);
		count += 2, i++;
	}

	return (count);
}
