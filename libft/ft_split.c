/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_
.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:04:47 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/13 13:35:53 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by 
ting ’s’ using the
character ’c’ as a delimiter.  The array must end
with a NULL pointer.

Parameters:
	s:  The string to be 
	.
	c:  The delimiter character.

Return:
	the array of new strings resulting from the 
	.
	NULL if the allocation fails.

char **ft_
(char const *s, char c);

Why + 2?
	i + 1 to match the size value + 1 for \0  

*/

#include "libft.h"

static size_t		ft_count_words(char const *s, char c);
static size_t		ft_write_matrix(char const *s, char c,
						size_t cnt_words, char	**pptr);
static int			ft_init_parameters(t_loop_elm *loop, char const *s);
static int			ft_loop(char const *s, char **pptr, t_loop_elm *loop);

char	**ft_split(char const *s, char c)
{
	char	**pptr;
	size_t	cnt_words;
	int		j;

	if (s == NULL)
		return (NULL);
	cnt_words = (ft_count_words(s, c));
	pptr = (char **)malloc((cnt_words + 1) * sizeof(pptr));
	if (pptr == 0)
		return (0);
	ft_memset(pptr, 0, (cnt_words + 1));
	j = ft_write_matrix(s, c, cnt_words, pptr);
	if (j == -1)
	{
		free(pptr);
		return (NULL);
	}	
	pptr[j] = 0;
	return (pptr);
}

static int	ft_init_parameters(t_loop_elm *loop, char const *s)
{
	if (loop == 0)
		return (0);
	loop->size_str = ft_strlen(s);
	loop -> i = 0;
	loop -> j = 0;
	loop -> k = 0;
	loop -> cnt = 0;
	return (1);
}

static int	ft_loop(char const *s, char **pptr, t_loop_elm *loop)
{
	pptr[loop->j] = (char *)malloc ((loop->cnt + 1) * sizeof(char));
	if (pptr[loop->j] == 0)
	{
		loop->j--;
		while (loop->j)
		{
			free(pptr[loop->j]);
			loop->j--;
		}
		free(pptr);
		free(loop);
		return (0);
	}
	ft_memset(pptr[loop->j], '\0', (loop->cnt + 1));
	while (loop->cnt > 0)
	{
		pptr[loop->j][loop->k] = s[loop->i - loop->cnt];
		loop->cnt--;
		loop->k++;
	}				
	loop->j++;
	loop->k = 0;
	return (1);
}

static size_t	ft_write_matrix(char const *s, char c,
				size_t cnt_words, char	**pptr)
{
	t_loop_elm	*lp;
	size_t		out;

	lp = malloc(sizeof(t_loop_elm));
	if (ft_init_parameters(lp, s) == 0)
		return (-1);
	while (lp->i <= lp->size_str && cnt_words > 0)
	{
		if (s[lp->i] != c)
			lp->cnt++;
		if (s[lp->i] == c || (lp->i < lp->size_str && s[lp->i + 1] == '\0'))
		{
			if (s[lp->i + 1] == '\0' && s[lp->i] != c)
				lp->i++;
			if (lp->cnt > 0)
				if (ft_loop(s, pptr, lp) == 0)
					return (-1);
		}		
	lp->i++;
	}
	out = lp->j;
	free(lp);
	return (out);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	cnt;
	size_t	i;
	int		sw;

	cnt = 0;
	i = 0;
	sw = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && sw == 0)
			sw = 1;
		else if (sw == 1)
		{
			if (s[i] == c || s[i + 1] == '\0')
			{
				sw = 0;
				cnt++;
			}	
		}
		if (sw == 1 && s[i + 1] == '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

/*
#include <stdio.h>
#include <unistd.h>
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}


int	main(void)
{
	// char	str[]= "cut this setehnce";
	// char	c = 'h';

	// char	str[]= "";
	// char	c = 'h';

	// char	str[]= "cut this setence";
	// char	c = '\0';
	
	// char	str[]= "";
	// char	c = '\0';

	// char	str[] = "   
	  //     this for   me  !       ";
	// char	c = ' ';

	// char *str = " olol";
	// char	c = ' ';

	char *str = "      this for   me  !       ";
	char	c = ' ';

	// char *str = "|!|";
	// char c = '|';

	// char *str = "          ";
	// char c = ' ';

	// char *str = "lorem ipsum dolor sit amet, 
	//consectetur adipiscing elit. Sed non risus. Suspendisse";
	// char c = ' ';

	char	**pptr = 0;
	// test ft_count_words

	size_t	n_words = ft_count_words(str, c) ;
	printf("count words: %lu\n", n_words);

	pptr = ft_split(str, c);

	//printf("%p\n", (char *)pptr);

	size_t	i;
	// size_t	j;

	i = 0;
	// j = 0;
	
	//while (pptr[i][j]!= '\0')
	// while (i < n_words)
	 //while (pptr[i] != NULL)
	 //while (i < n_words + 1)
	//{
	//	printf("pptr[%lu] = '%s'\n", i, pptr[i] );
	//	i++;
		//j++;
		//free(pptr[i]);
	//}

		while (pptr[i] != NULL)
			{
				ft_print_result(pptr[i]);
				write(1, "\n", 1);
				i++;
			}

		
	//}
	free(pptr);
	//char	**ptr;

	//ptr = ft_
	//(str, c);

	//char **expected = ((char*[6]){"
	// ", "this", "for", "me", "!", ((void *)0)});
	// //printf("ist: '%s'\n", *(ptr));
	// //free (ptr);
	return (0);
}

int main(void)
{
	char	**tabstr;
	int		i = 0;

	if (!(tabstr = ft_split("check this for me", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}

}



int main(void)
{
	char	**tabstr;
	int		i;

	i = 0;
	if (!(tabstr = ft_split("lorem ipsum dolor sit amet,
	//consectetur adipiscing elit. Sed non risus. Suspendisse 
	//lectus tortor, dignissim sit amet, adipiscing nec, 
	//ultricies sed, dolor. Cras elementum ultricies diam. 
	//Maecenas ligula massa, varius a, semper congue, 
	//euismod non, mi.", 'i')))
		ft_print_result("NULL");
	else
	{
		while (tabstr[i] != NULL)
		{
			ft_print_result(tabstr[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}


#include <unistd.h>

static void ft_free_pptr(char **pptr, size_t j)
{
	size_t i;

	i = 0;
	while (j >= 0 && i <= j)
	{
		free(pptr[i]);
		i++;
	}
	free(pptr);
}


void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int main (void)
{

char 	**tab = ft_split("  tripouille  42  ", ' ');
int		i;

i = 0;

write(1, "\n\nResult is : \n", 15);

while (tab[i] != NULL)
		{
			ft_print_result(tab[i]);
			write(1, "\n", 1);
			i++;
		}
		write(1, "\n", 1);
//if (tab[2] == NULL)
// 	tab[2] = '*';

ft_free_pptr(tab, 2);

/// 6 check(tab[2] == NULL);
//	freeTab(tab); showLeaks();
return (0);
} 
*/