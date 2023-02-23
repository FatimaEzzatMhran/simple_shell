#include "main.h"
/**
 * _printf - printf function
 * @format: string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arglist;
	int count = 0, i = 0;

	va_start(arglist, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += checkSpecifier(format, i, arglist);
			i++;
		}
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
			return (-1);
		i++;
	}
	va_end(arglist);
	return (count);
}

/**
 * _printp - prints int to hexadecimal
 * @arglist: list of arguments
 *
 * Return: number of characters printed
 */
int _printp(va_list arglist)
{
	uintptr_t ptr = va_arg(arglist, uintptr_t);
	int i = 0;

	if (ptr == 0)
	{
		write(1, "(", 1);
		write(1, "n", 1);
		write(1, "i", 1);
		write(1, "l", 1);
		write(1, ")", 1);
		return (5);
	}

	write(1, "0", 1);
	write(1, "x", 1);
	i += 2;
	i += write_x(ptr);

	return (i);
}
