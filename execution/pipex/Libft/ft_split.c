/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:31:22 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/14 00:14:54 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_return_array_size(char const *s, char c,
									int i, int delimiter_count)
{
	int	enter_flag;

	enter_flag = 0;
	while (s[i])
	{
		if (s[i] != c && enter_flag == 0)
		{
			enter_flag = 1;
			delimiter_count++;
		}
		else if (s[i] == c)
			enter_flag = 0;
		i++;
	}
	return (delimiter_count);
}

static char	*extract_word(char *word_start, int *word_size)
{
	int		count;
	int		word_start_cnt;
	char	*word;

	count = 0;
	word_start_cnt = 0;
	word = malloc(sizeof(char) * (*word_size + 1));
	if (!word)
		return (0);
	while (count != *word_size)
		word[count++] = word_start[word_start_cnt++];
	word[count] = '\0';
	*word_size = 0;
	return (word);
}

static int	change_values(char **word_start, const char *s,
							int *word_size, int *i)
{
	*word_start = (char *)&s[*i];
	*word_size = *word_size + 1;
	return (1);
}

static char	**fill_return_array(char **rtn, char const *s, char c, int i)
{
	char	*word_start;
	int		word_size;
	int		enter_flag;
	int		cnt;

	cnt = 0;
	enter_flag = 0;
	word_size = 0;
	while (s[i])
	{
		if (s[i] != c && enter_flag != 1)
			enter_flag = change_values(&word_start, s, &word_size, &i);
		else if (s[i] == c)
			enter_flag = 0;
		else
			word_size++;
		if (enter_flag == 0 && word_size > 0)
			rtn[cnt++] = extract_word(word_start, &word_size);
		i++;
		if ((size_t)i >= ft_strlen(s) && enter_flag == 1 && word_size > 0)
			rtn[cnt++] = extract_word(word_start, &word_size);
	}
	rtn[cnt] = 0;
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		delimiter_count;
	int		i;

	i = 0;
	delimiter_count = 0;
	delimiter_count = count_return_array_size(s, c, i, delimiter_count);
	rtn = malloc(sizeof(char *) * (delimiter_count + 1));
	if (!rtn)
		return (0);
	i = 0;
	rtn = fill_return_array(rtn, s, c, i);
	return (rtn);
}
