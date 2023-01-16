/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_allocated_mem.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:41:15 by mgranero          #+#    #+#             */
/*   Updated: 2022/10/25 15:51:45 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ----------------------------Error Management-----------------------------

 This Module is responsible for receiving the output of the functions that
 returns errors, prints the correct error message for the error id it 
 received. Free pointers in array of allocated memory arr_allocd_mem
 inside a_smen.
 ----------------------------------------------------------------------------
*/

/*
- Function: ft_free_all_allocated_mem								
- Description:					
	In case of error detected, this function is called to loop the
	array of allocated memory arr_allocd_mem inside s_smen and
	free every pointer before returning -1 to the calling function
	that will stop the program run.								
- Prototype:	
	void ft_free_all_allocated_mem(struct s_mem *mem)								
- Inputs:					
	struct  s_mem mem
- Returns:			
*/

void	ft_free_all_allocated_mem(struct s_mem *mem)
{
	int	i;

	if (mem->len_arr_allocd_mem > 0)
	{
		i = mem->len_arr_allocd_mem - 1;
		while (mem->len_arr_allocd_mem > 0 && i > 0)
		{
			if (mem->arr_allocd_mem[i] != 0)
				free(mem->arr_allocd_mem[i]);
			i--;
		}
		if (mem->arr_allocd_mem[0] != 0)
			free(mem->arr_allocd_mem[0]);
		free(mem->arr_allocd_mem);
	}
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

int	main(void)
{
	int				i;
	struct s_mem	smem;
	struct s_mem	*mem;
	int				size_desired;

	// mem Initialization
	mem = &smem;
	mem->arr_allocd_mem = 0;
	mem->len_arr_allocd_mem = 0;
	mem->error_id = 0;
	
	i = 0;
	size_desired = 4;
	// Allocating 4 elements in the array arr_allocd_mem
	while (mem->len_arr_allocd_mem < size_desired)
		ft_mem_calloc(size_desired, sizeof(char), mem);
	printf("Pointers allocated in mem->arr_allocd_mem\n");
	array_print(mem->arr_allocd_mem, mem->len_arr_allocd_mem);
	printf("---------------------------------------");

	// calling functions to be tested

	while (i < NUMBER_OF_ENUM_ERRORS)
	{
		mem->error_id = i;
		ft_error_manager(mem);
		i++;
	}
	return (0);
}
*/