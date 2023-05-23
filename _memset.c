#include "shell.h"

/**
 * _memset - covers mem with a const byte
 * @s: the memory areas pointer
 * @b: the byte that will fill *s 
 * @n: the quantity of bytes that will be filled
 * Return: (s) a pointer to the memory area represented by s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - deallocates a dynamic array of strings
 * @pp: collection of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the previously allocated memory block
 * @old_size: size in bytes of the previous block
 * @new_size: ize in bytes of the new block
 *
 * Return: pointer to the old block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
