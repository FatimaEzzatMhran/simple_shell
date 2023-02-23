#include "main.h"
int write_b(unsigned int);
/**
  * _printb - Handling the %b format specifier of _printf
  * @arg: Current argument
  *
  * Return: Number of character of the argument
  */

int _printb(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int);

	return (write_b(n));
}

/**
  * write_b - print binary format
  * @number: number to convert to binary
  *
  * Return: length of the number
  */

int write_b(unsigned int number)
{
	int count = 0, temp;

	if (number / 2)
		count = write_b(number / 2);

	temp = number % 2;
	temp += '0';

	count++;
	write(1, &temp, 1);

	return (count);
}

/**
 * _printo - prints integer to octal
 * @arglist: list of arguments
 *
 * Return: number of characters printed
 */
int _printo(va_list arglist)
{
	unsigned int n = va_arg(arglist, unsigned int);

	return (write_octal(n));
}

/**
 * write_octal - prints integer to octal with write's function
 * @number: integer;
 * Return: number of characters printed
 */
int write_octal(unsigned int number)
{
	int temp, characters_printed;

	characters_printed = 0;
	if (number / 8)
	{
		characters_printed = write_octal(number / 8);
	}
	temp = number % 8 + '0';
	return ((characters_printed + write(1, &temp, 1)));
}
