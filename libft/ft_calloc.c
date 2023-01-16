/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:51:17 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/22 09:55:22 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdlib.h>
NAME
calloc, free, malloc, realloc, reallocf, valloc, aligned_alloc -- memory 
allocation

DESCRIPTION
The malloc(), calloc(), valloc(), realloc(), and reallocf() functions allocate
memory.  The allocated memory is aligned such that it can be used for any data
type, including AltiVec- and SSE-related types.  The aligned_alloc() function
allocates memory with the requested alignment.  The free() function frees allo-
cations that were created via the preceding allocation functions.

The malloc() function allocates size bytes of memory and returns a pointer to
the allocated memory.

The calloc() function contiguously allocates enough space for count objects 
that are size bytes of memory each and returns a pointer to the allocated 
memory. The allocated memory is filled with bytes of value zero.

The realloc() function tries to change the size of the allocation pointed 
to by ptr to size, and returns ptr.  If there is not enough room to enlarge
the memory allocation pointed to by ptr, realloc() creates a new allocation,
copies as much of the old data pointed to by ptr as will fit to the new 
allocation, frees the old allocation, and returns a pointer to the allocated
memory.  If ptr is NULL, realloc() is identical to a call to malloc() for 
size bytes.  If size is zero and ptr is not NULL, a new, minimum sized 
object is allocated and the original object is freed.  When extending 
a region allocated with calloc(3), realloc(3) does not guarantee that 
the additional memory is also zero-filled.

void * calloc(size_t count, size_t size);

void free(void *ptr);

void * malloc(size_t size);
void * realloc(void *ptr, size_t size);
*/
#include "libft.h"

void	*ft_calloc(size_t count, size_t size_of_type)
{
	void	*ptr;

	if (count >= SIZE_MAX || size_of_type >= SIZE_MAX
		|| count * size_of_type >= SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size_of_type);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, count * size_of_type);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	int n_of_added_elem;
	char * array = 0;

	n_of_added_elem = 4;
	printf("Memory initialized at %p\n", (void *)array);
	printf("Increase Array Size to +4 Bytes\n");
	array = (char *) calloc(n_of_added_elem, sizeof(char));

	if (array == 0)
	{
		printf("Error - no memory allocated\n");
	}
	printf("Memory allocated at %p\n", (void *)array);
	free((void *)array);
	return (0);
}
*/