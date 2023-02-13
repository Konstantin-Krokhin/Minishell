/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:20:05 by mgranero          #+#    #+#             */
/*   Updated: 2023/01/25 21:29:32 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief function will return the index of the first match of the character
 *  c in the string str. If not found, it returns -1.
 *
 * @param str string where c will be searched
 * @param c  character to be searched in str
 * @return int -1 if no character not found, otherwise the index of the first
 *   match.
 */
int	get_char_index(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
