#include "main.h"
/**
 * _strdup - allocated space in memory with a copy of string
 * @str: string
 *
 * Return: pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *ptr;
	int length, i, j;

	if (str == NULL)
		return (NULL);
	for (length = 0; str[length]; length++)
		;
	ptr = malloc((length + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	for (i = 0, j = 0; i < length; i++, j++)
		ptr[j] = str[i];
	ptr[j] = '\0';
	return (ptr);
}

/**
 * _strstr - Located a substring.
 * @haystack: String with search the occurence to.
 * @needle: Substring searched in haystack
 *
 * Return: Pointer to the beggining of the located substring, otherwise NULL
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0, y = 0, count = 0, temp, size = 0;

	while (needle[size] != '\0')
		size++;

	while (haystack[i] != '\0')
	{
		temp = i;
		while (needle[y] != '\0')
		{
			if (haystack[i] == needle[y])
				count++;
			i++;
			y++;
		}
		if (count == size)
			return (haystack + temp);
		y = count = 0;
		i = temp;
		i++;
	}
	return (0);
}
