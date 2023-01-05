/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_pointer_from_array.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:21:00 by mgranero          #+#    #+#             */
/*   Updated: 2022/10/24 22:34:58 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ----------------------------Utilitary Functions-----------------------------

 In this section it is described the plan for the utils function that will 
 support the implementation of different functions in different modules.

 ----------------------------------------------------------------------------
*/

int	ft_remove_pointer_from_array(void *ptr_allocd,
			struct s_mem *mem, int index)
{
	void	**arr_allocd_tmp;

	if (mem->len_arr_allocd_mem > 1)
	{
		arr_allocd_tmp = ft_calloc(mem->len_arr_allocd_mem - 1,
				sizeof(ptr_allocd));
		if (arr_allocd_tmp == 0)
		{
			mem->error_id = ERR_MEM_DEALLOC;
			return (1);
		}
		ft_memcpy((arr_allocd_tmp), (mem->arr_allocd_mem),
			index * sizeof(ptr_allocd));
		if (index < mem->len_arr_allocd_mem - 1)
			ft_memcpy((arr_allocd_tmp + index),
				(mem->arr_allocd_mem + index + 1),
				(mem->len_arr_allocd_mem - index - 1) * sizeof(ptr_allocd));
		free(mem->arr_allocd_mem[index]);
		if (index != 0)
			free(mem->arr_allocd_mem);
		mem->arr_allocd_mem = arr_allocd_tmp;
	}
	else
		free(mem->arr_allocd_mem);
	return (0);
}

// -------- TESTING FUNCTIONS -----
/*
#include <stdio.h>

static void array_print(void **arr_ptr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("[%d]: ptr = %p\n", i, (arr_ptr[i]));
		i++;
	}
}

static void ft_allocating_pointers_test(struct s_mem *mem, int size_desired)
{
	// Allocating 4 elements in the array arr_allocd_mem
	while (mem->len_arr_allocd_mem < size_desired)
		ft_mem_calloc(size_desired, sizeof(char), mem);
	printf("allocating pointers\n");
	array_print(mem->arr_allocd_mem, mem->len_arr_allocd_mem);
	printf("-----\n");
}

static void ft_deallocing_pointers_test(struct s_mem *mem, void *ptr_2_dealloc)
{
	printf("pointer to be deallocate %p\n",ptr_2_dealloc);
	ft_mem_dealloc(ptr_2_dealloc, mem);
	printf("------\n");
	array_print(mem->arr_allocd_mem, mem->len_arr_allocd_mem);
	printf("********\n");
}

int main(void)
{
	struct s_mem	smem;
	struct s_mem	*mem;
	int				size_desired;
	int 			i;

	// mem Initialization
	mem = &smem;
	mem->arr_allocd_mem = 0;
	mem->len_arr_allocd_mem = 0;
	mem->error_id = 0;

	//--- Create 4x pointers of size 4 char's
	size_desired =  4;

	// Allocating Dynamic Memory 
	printf("-->Testing pointer allocations\n");
	ft_allocating_pointers_test(mem, size_desired);

	// -----Test dealloc in alternate pointer order------
	  printf("\n-->Test dealloc in alternate pointer order\n");
	  // from the middle position
	  ft_deallocing_pointers_test(mem, mem->arr_allocd_mem[2]);
	  // last position
	  ft_deallocing_pointers_test(mem, mem->arr_allocd_mem[2]);
	  // first position
	  ft_deallocing_pointers_test(mem, mem->arr_allocd_mem[0]);
	  // last element
	  ft_deallocing_pointers_test(mem, mem->arr_allocd_mem[0]);
	  printf("--------------------------------------------\n");

	// -----Test free all in order------------------------
	printf("\n->Test dealloc in order \n");
	printf("Pointer allocations\n");
	ft_allocating_pointers_test(mem, size_desired);
	i = 0;
	while (i < mem->len_arr_allocd_mem)
	{
		ft_deallocing_pointers_test(mem, mem->arr_allocd_mem[0]);
		i++;
	}
	printf("--------------------------------------------\n");
	// -----Test free all in re-verse oder----------------
	printf("\n-->Test dealloc in reverse order \n");
	printf("Pointer allocations\n");
	ft_allocating_pointers_test(mem, size_desired);
	i = size_desired - 1;
	while (i >= 0)
	{
		ft_deallocing_pointers_test(mem, mem->arr_allocd_mem[i]);
		i--;
	}
	// -----Test pointer input from pointer not in the array--
	printf("\n-->Test dealloc with pointer not on the list \n");
	printf("Pointer allocations\n");
	
	ft_allocating_pointers_test(mem, 2);
	ft_deallocing_pointers_test(mem, (void *)&i);
	printf("should not have removed anything\n");

	printf("\n\n cleaning up\n");
	ft_deallocing_pointers_test(mem, mem->arr_allocd_mem[0]);
	ft_deallocing_pointers_test(mem, mem->arr_allocd_mem[0]);


	return (0);
}
*/