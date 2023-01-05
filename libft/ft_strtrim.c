/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:10:09 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/21 12:03:55 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.

Parameter:
	s1:  The string to be trimmed.
	set:  The reference set of characters to trim.	

Return value:
	The trimmed string. NULL if the allocation fails.

char *ft_strtrim(char const *s1, char const *set);
*/
#include "libft.h"

static size_t	ft_find_right_cut(char const *s1,
					char const *set, size_t size_s1);
static size_t	ft_find_left_cut(char const *s1,
					char const *set, size_t size_s1);
static void		ft_write_str_out(char const *s1,
					char *str_out, size_t idx_left,
					size_t idx_right);
static int		ft_char_set_in_str(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_s1;
	size_t	idx_left;
	size_t	idx_right;
	char	*str_out;

	if (s1 == 0 || set == 0)
		return (NULL);
	size_s1 = ft_strlen(s1);
	idx_left = ft_find_left_cut(s1, set, size_s1);
	idx_right = ft_find_right_cut(s1, set, size_s1);
	if (idx_left == size_s1 || s1[0] == '\0')
	{
		str_out = (char *) malloc(sizeof(char) * (1));
		str_out[0] = '\0';
		return (str_out);
	}
	str_out = (char *)malloc(sizeof(char) * (idx_right - idx_left + 2));
	if (str_out == 0)
		return (0);
	ft_write_str_out(s1, str_out, idx_left, idx_right);
	return (str_out);
}

static size_t	ft_find_left_cut(char const *s1,
				char const *set, size_t size_s1)
{
	size_t	i;

	i = 0;
	while (i < size_s1)
	{
		if (ft_char_set_in_str(s1[i], set) == 1)
		{
			i++;
		}
		else
		{
			return (i);
		}
	}
	return (i);
}

static size_t	ft_find_right_cut(char const *s1,
				char const *set, size_t size_s1)
{
	size_t	i;

	i = size_s1 - 1;
	while (i > 0)
	{	
		if (ft_char_set_in_str(s1[i], set) == 1)
		{
			i--;
		}
		else
		{	
			return (i);
		}
	}
	return (i);
}

static void	ft_write_str_out(char const *s1, char *str_out,
				size_t idx_left, size_t idx_right)
{
	size_t	i;
	size_t	j;

	i = idx_left;
	j = 0;
	while (i <= idx_right)
	{
		str_out[j] = s1[i];
		j++;
		i++;
	}
	str_out[j] = '\0';
}

static int	ft_char_set_in_str(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	//char	str_in[]= "buscar nessa palavra aqui";
	//char	set[]= "au";

	//char	str_in[]="  Neque porro quisquam";
	//char	set[]= " ";

	//char 	*str_in = "   \t  \n\n \t\t  \n\n\nHello \t  
	Please\n Trim me !";
	//char	set[] =  " \n\t";
	
	//char *str_in = "\t   \n\n\n  \n\n\t    Hello \t  
	Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
	//char	set[] =  " \n\t";

	//char *str_in = "Hello \t  Please\n Trim me !";
	//char	set[] =  " \n\t";

	char *str_in = "  \t \t \n   \n\n\n\t";
	char	set[] =  " \n\t";

	char	*str_out;
	
	str_out = 0;
	str_out = ft_strtrim(str_in, set);
	printf(" ist: '%s' and lenght %lu\n", str_out, 
	ft_strlen(str_out));
	free(str_out);
	return (0);
}*/