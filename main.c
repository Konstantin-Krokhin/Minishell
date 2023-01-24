/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:21:04 by mgranero          #+#    #+#             */
/*   Updated: 2023/01/24 21:16:58 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void print_intro(void);

/**
 * @brief
 *
 * @return int a number different than 0 in case of error
 */
int	main(void)
{
	char	*buff;
	char	*cmd;
	char	**args;
	int		err_status;

	print_intro();
	err_status = 0;
	while (1)
	{
		buff = readline(">>");
		if (ft_strlen(buff) > 0)
			 add_history(buff);
		//PARSE INPUT
		args = 0; //intialized
		cmd = 0; //intialized
		// if (parser(buff, cmd, args) == 1)
		// {
		// 	err_status = 1;
		// 	break;
		// }
		//CALL COMMANDS
		//PIPE
		// REDIRECT
		free(buff);
	}
	if (err_status == 1)
	{
		free(buff);
		write(2, "Error: parser\n", 14);
		return (1);
	}
	return (0);
}

/**
 * @brief function will print the intro characters by program initialization
 */
static	void print_intro(void)
{
	printf("\n%s      . . . . .    \n  ..         42..\n ..             ..\n", CCYN);
	printf(".     .. ..      ..\n..   .      .    ..\n..   .   .   .   ..\n");
	printf(" ..    ..    .   ..\n  ..        .    .\n    .. .. ..    ..\n\n%s", CNRM);
	printf("%s   oh my Minishell!\n   ---------------%s\n",CGRN, CNRM);
}
