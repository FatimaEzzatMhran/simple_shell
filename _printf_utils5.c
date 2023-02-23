#include "main.h"
/**
 * _printx - prints int to hexadecimal
 * @arglist: list of arguments
 *
 * Return: number of characters printed
 */
int _printx(va_list arglist)
{
	unsigned int n = va_arg(arglist, unsigned int);

	return (write_x(n));
}
/**
 * write_x - prints int to hexadecimal with write's function
 * @number: integer
 *
 * Return: number of character
 */
int write_x(unsigned long int number)
{
	int arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int temp, index, characters_printed;

	characters_printed = 0;
	if (number / 16)
	{
		characters_printed = write_x(number / 16);
	}
	temp = number % 16;
	if (temp > 9)
	{
		characters_printed++;
		index = temp - 10;
		write(1, &arr[index], 1);
	}
	else
	{
		characters_printed++;
		temp += '0';
		write(1, &temp, 1);
	}
	return (characters_printed);
}

/**
 * _printX - prints int to hexadecimal
 * @arglist: list of arguments
 *
 * Return: number of characters printed
 */
int _printX(va_list arglist)
{
	unsigned int n = va_arg(arglist, unsigned int);

	return (write_X(n));
}
/**
 * write_X - prints int to hexadecimal with write's function
 * @number: integer
 *
 * Return: number of character
 */
int write_X(unsigned int number)
{
	int arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int temp, index, characters_printed;

	characters_printed = 0;
	if (number / 16)
	{
		characters_printed = write_X(number / 16);
	}
	temp = number % 16;
	if (temp > 9)
	{
		characters_printed++;
		index = temp - 10;
		write(1, &arr[index], 1);
	}
	else
	{
		characters_printed++;
		temp += '0';
		write(1, &temp, 1);
	}
	return (characters_printed);
}
