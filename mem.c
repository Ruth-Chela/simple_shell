#include "shell.h"

/**
 * bfree - NULLs the address and frees the Ptr
 * @ptr: Ptr to free
 *
 * Return: If freed 1, otherwise 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
