/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:26:04 by mgranero          #+#    #+#             */
/*   Updated: 2023/01/24 21:03:35 by mgranero         ###   ########.fr       */
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
int	parser(char *buff, char *cmd, char **args)
{
	printf("buffer is: %s\n", buff);
	cmd = buff;
	args = &buff;

	return (0);
}


/*
 Parser.c Test main
*/
int main(void)
{
	char buff[] =  "cd ..";
	char *cmd;
	char **args;
	int res;
	int i = 0;

	cmd = 0;
	args = 0;
	res = parser(buff, cmd, args);
	printf("parser returned value %d\n", res);
	printf("cmd is: %s\n", cmd);
	if (cmd != 0)
		free(cmd);
	while (args[i] != 0)
	{
		printf("args[%d]= %s\n", i, args[i]);
		if (args[i] != 0)
			free(args[i]);
		i++;
	}
	free(args);
	return (0);
}
