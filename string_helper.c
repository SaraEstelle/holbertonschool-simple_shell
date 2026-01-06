#include "simple_shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);

	while (s[len])
		len++;

	return (len);
}

/**
 * _strdup - Duplicates a string
 * @str: string to duplicate
 * Return: pointer to duplicated string or NULL if fails
 */
char *_strdup(char *str)
{
	char *dup;
	int i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		;

	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		dup[i] = str[i];

	dup[i] = '\0';
	return (dup);
}

/**
 * _strcmp - Compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, <0 or >0 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncmp - Compares first n chars of two strings
 * @s1: first string
 * @s2: second string
 * @n: number of chars
 * Return: 0 if equal, <0 or >0 otherwise
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0')
			break;
	}
	return (0);
}

/**
 * _strchr - Finds first occurrence of char in string
 * @s: string
 * @c: character
 * Return: pointer to char or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i;

	if (s == NULL)
		return (NULL);

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (s + i);
	}

	if (c == '\0')
		return (s + i);

	return (NULL);
}
