#include "main.h"
/**
 * _strcmpdir - compares strings to find dir.
 *
 * @s1: string.
 * @s2: string.
 *
 * Return: if match and any other number if otherwise.
 **/
int _strcmpdir(char *s1, char *s2)
{
	int strc = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (strc == 3)
			break;
		strc++;
		s2++;
	}

	return (*s1 - *s2);
}
/**
 * charput - writes the character like putchar
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int charput(char c)
{
	return (write(1, &c, 1));
}

/**
 * place - similar to puts in C
 * @str: a pointer the integer we want to set to 402
 *
 * Return: int
 */
void place(char *str)
{
	while (*str != '\0')
	{
		charput(*str);
		str++;
	}
}

/**
 * _strlen - Len string.
 * @str: My string.
 * Return: Length.
 */
int _strlen(char *str)
{
	int slen;

	for (slen = 0; str[slen] != '\0'; slen++)
		;

	return (slen);
}

/**
 * str_concat - concatane strings.
 * @s1: string.
 * @s2: second string.
 * Return: strings.
 */
char *str_concat(char *s1, char *s2)
{
	char *a;
	int lens1, lens2, x, w, e;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	lens1 = _strlen(s1);

	lens2 = _strlen(s2);

	a = malloc(((lens1) + (lens2) + 1) * sizeof(char));

	if (a == NULL)
		return (NULL);

	for (x = 0; x < lens1; x++)
	{
		a[x] = s1[x];
	}

	for (w = lens1, e = 0; e <= lens2; w++, e++)
	{
		a[w] = s2[e];
	}
	return (a);
}
