#include "main.h"

/**
 * _strcpy - makes a copy of a string
 * @dest: address of buffer to copy string to
 * @src: address of string to be copied
 *
 * Return: the pointer to dest. Otherwise NULL
 */
char *_strcpy(char *dest, const char *src)
{
	unsigned int scpy;

	if (src == NULL || dest == NULL)
		return (NULL);

	for (scpy = 0; src[scpy] != '\0'; scpy++)
		dest[scpy] = src[scpy];

	dest[scpy] = '\0';

	return (dest);
}

/**
 * _strlen - finds the length of a given string
 * @str: given string
 *
 * Return: length of str
 */
unsigned int _strlen(const char *str)
{
	unsigned int len = 0;

	if (str == NULL)
		return (0);

	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}

/**
* _strcmp - compares 2 strings
* @s1: first string
* @s2: second string
*
* Description: works exactly like strcmp from <string.h>
*
* Return: -ve integer, 0 or +ve integer if s1 is less than,
* equal to or greater than s2
*/
int _strcmp(const char *s1, const char *s2)
{
	int diff = 0;

	while (diff == 0)
	{
		diff = *s1 - *s2;

		/* break if one of the strings is empty */
		if (*s1 == '\0' || *s2 == '\0')
			break;

		s1++;
		s2++;
	}

	return (diff);
}

/**
 * _strdup - creates a copy of a given string
 * @str: string to copy
 *
 * Return: new string identical to str. Otherwise NULL
 */
char *_strdup(const char *str)
{
	unsigned int len;
	char *result;

	if (str == NULL)
		return (NULL);

	/* allocate space for new string */
	len = _strlen(str);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);

	/* copy contents of str into new string */
	return (_strcpy(result, str));
}

/**
 * _strtok - tokenizes a given string using a given delimiter
 * @str: string
 * @delim: delimiter
 *
 * Return: pointer to next token. Otherwise NULL
 */
char *_strtok(char *str, const char *delim)
{
	char c;
	int found_char = 0;
	char *start;
	static char *current;

	start = (str ? str : current);

	if (str)
		current = str;

	if (delim == NULL || *current == '\0')
		return (NULL);

	c = delim[0];

	while (*current == c) /* ignore separators at beginning */
	{
		start++;
		current++;
	}

	while (*current)
	{
		if (*current == c && found_char) /* found a delimiter */
		{
			*current = '\0';
			current++;
			break;
		}

		found_char = 1;
		current++;
	}

	while (*current && *current == c) /* ignore separators at end */
		current++;

	return (_strlen(start) ? start : NULL);
}

/**
 * is_in_str - checks whether given character is in a given string
 * @str: string
 * @c: character
 *
 * Return: 1 if c is in str. 0 Otherwise
 */
int is_in_str(const char *str, char c)
{
	if (str == NULL)
		return (0);

	while (*str)
	{
		if (*str == c)
			return (1);

		str++;
	}

	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: string
 *
 * Return: integer equivalent. Otherwise -1
 */
int _atoi(char *str)
{
	int x, j, n, result;

	if (str == NULL)
		return (-1);

	n = _strlen(str);

	for (x = n - 1, j = 1, result = 0; x >= 0; x--, j *= 10)
	{
		if (result < 0 || str[x] > '9' || str[x] < '0')
			return (-1);

		result += (str[x] - '0') * j;
	}

	return (result % 256);
}

/**
 * str_rep - replaces all occurences of a non printable character
 * in a string with space
 * @str: string
 */
void str_rep(char *str)
{
	while (*str)
	{
		if (*str < ' ')
			*str = ' ';

		str++;
	}
}
