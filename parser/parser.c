/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:26:04 by mgranero          #+#    #+#             */
/*   Updated: 2023/02/13 15:04:12 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief function will receive a buffer input and parse the input and save
 *  the command to be called inside cmd and the arguments to be passed to
 *  the command as args.
 *
 * @param buff string containing the input arguments to be parsed.
 * @param cmd string where the command will be written. cmd must be free
 * @param args array of strings where arguments will be writte. Last argument is
 *   a pointer to 0, indicating end of the array. all args must be free and
 *   args it self.
 * @return int returns a number a different than 0 in case of error. Otherwise
 * 	returns 0.
 */


/*
	array of cmds and args (multiple)

	enum{
		TRUE,
		FALSE
	}    e_bool;

	arr_commands

	typedef struct  commands
		char *cmd   //one string
		char **args "arg1\0", "arg2\0, 0"
		pipe_in  TRUE or FALSE
		pipe_out TRUE or FALSE
		redirect_in TRUE or FALSE
		redirect_out TRUE or FALSE
		delimiter_in TRUE or FALSE
		append_out TRUE or FALSE
		ret_exit_status TRUE or FALSE

	char	*ft_strdup(const char *s1)

	char	*ft_substr(char const *s, unsigned int start, size_t len)

*/

/*
	returns 0 in case of error
*/
t_commands	*parser(char *buff)
{
	t_commands	*arr_commands;
	int			index;
	int			start;
	int			len;

	if (buff == 0 || buff[0] == '\0')
		return (0);
	index = get_char_index(buff, ' ');
	if (index == -1)
		printf("get_char_index returned -1\n");
	start = 0;
	arr_commands = (t_commands *)malloc(sizeof(t_commands) * 2);
	if (arr_commands == 0)
	{
		printf("Error: malloc for arr_commands returned 0\n");
		return (0);
	}

	ft_memset(arr_commands, 0, sizeof(t_commands) * 2);
	arr_commands[0].cmd = ft_substr(buff, start, index);
	start = index + 1;
	index = ft_strlen(buff);
	arr_commands[0].args = (char **)malloc(sizeof(char *)* 1); //only one args
	arr_commands[0].args[0] = ft_substr(buff, start, index);

	return (arr_commands);
}


/*
 Parser.c Test main
*/
int main(void)
{
	char 		buff[] =  "cd ..\0";
	t_commands	*arr_commands;

	printf("buffer is: %s\n", buff);
	arr_commands = parser(buff);

	// free arr_commands function
	int i;
	int j;

	i = 0;
	if (arr_commands != 0)
	{
		while (arr_commands[i].cmd != 0)
		{
			printf("commands: %s\n", arr_commands[i].cmd);
			free(arr_commands[i].cmd);
			j = 0;
			while (arr_commands[i].args[j] != 0)
			{
				printf("args: %s\n", arr_commands[i].args[j]);
				free(arr_commands[i].args[j]);
				j++;
			}
			free(arr_commands[i].args);
			free(arr_commands + i);
			i++;
		}
	}
	return (0);
}


/*
	test name			input			expected parser return value
	buff pointer 0		buff = 0;				0
	butt empty			buff = '\0';			0

*/