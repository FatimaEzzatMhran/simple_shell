#include "main.h"

/**
 * _strcmp - Compares to strings
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Return: Difference between the first two characters who are different
 */

int _strcmp(char *s1, char *s2)
{
	int number = 0, i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue;
		}
		number = s1[i] - s2[i];
		break;
	}
	return (number);
}

/**
 * _strcpy - copies the string to the ptr
 * @dest: destincation
 * @src: src
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - count characters in a string
 * @str: a string
 *
 * Return: number of characters
 */
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/**
 * number_of_words - count the number of words in a string
 * @str: a string
 * @separator: separator use to split the string
 * Return: number of words
 */
int number_of_words(char *str, char *separator)
{
	int i = 0, etat, nm = 0;

	if (str == NULL)
		return (0);

	etat = DEHORS;
	while (str[i])
	{
		if (str[i] == separator[0] || str[i] == separator[1])
			etat = DEHORS;
		else if (etat == DEHORS && str[i] != '\n')
		{
			etat = DEDANS;
			++nm;
		}
		i++;
	}
	return (nm);
}

/**
 * *_strcat - function appends the src string to the dest
 * @src: source
 * @dest: destination
 *
 * Return: pointer with concatenat string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j]; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
