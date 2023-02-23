#include "main.h"

/**
 * _getenv - Get an environment variable.
 * @name: Variable to look for
 *
 * Return: The environnment variable, if not found NULL
 */

char *_getenv(const char *name)
{
	int i = 0, y, count = 0, length;
	char *copy = (char *)name;

	if (name == NULL || !name[i])
		return (NULL);

	length = _strlen(copy);
	while (*(environ + i))
	{
		y = 0;
		while (*(*(environ + i) + y) != '=')
		{
			if (*(*(environ + i) + y) == name[y])
				count++;
			y++;
		}
		if (count == length)
		{
			y++;
			return (*(environ + i) + y);
		}
		i++;
		count = 0;
	}
	return (NULL);
}
