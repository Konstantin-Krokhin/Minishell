/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:21:04 by mgranero          #+#    #+#             */
/*   Updated: 2023/01/09 17:45:09 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char *buff;

	printf("-----Welcome to Minishell-----\n");
	while (1)
	{
		buff = readline(">>");
		if (ft_strlen(buff) > 0)
			 add_history(buff);

		//PARSE INPUT
		//CALL COMMANDS
		//PIPE
		// REDIRECT
		printf("%s\n",buff);
		free(buff);
	}
	return (0);
}
