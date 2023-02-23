#include "main.h"
/**
  * get_specifier_func - Select the correct function to perform depending
  * on the specifier on the printf format.
  * @c: specifier passed as an argument
  *
  * Return: Pointer to the function that correspond to the specifier given as a
  * parameter.
  */
int (*get_specifier_func(char c))(va_list)
{
	int i;
	type specifier[] = {
	    {'c', _printc},
	    {'s', _prints},
	    {'d', _printd},
	    {'i', _printd},
	    {'b', _printb},
	    {'u', _printu},
	    {'o', _printo},
	    {'x', _printx},
	    {'X', _printX},
	    {'S', _printS},
	    {'p', _printp},
	    {'R', _printR},
	    {'r', _printr},

	};

	i = 0;
	while (specifier[i].c)
	{
		if (specifier[i].c == c)
			return (specifier[i].ptr_f);
		i++;
	}

	return (NULL);
}
