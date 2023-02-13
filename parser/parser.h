/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:28:23 by mgranero          #+#    #+#             */
/*   Updated: 2023/02/13 14:40:10 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "stdio.h" // also present in main
#include "../libft/libft.h" // also present in main
# include <stdlib.h> // // also present in main

enum e_bool
{
	TRUE,
	FALSE,
};

typedef struct	s_command
{
	char	*cmd;   //one string
	char	**args; // "arg1\0", "arg2\0, 0"
	int		pipe_in; //  TRUE or FALSE
	int		pipe_out; // TRUE or FALSE
	int		redirect_in; // TRUE or FALSE
	int		redirect_out; // TRUE or FALSE
	int		delimiter_in; // TRUE or FALSE
	int		append_out; // TRUE or FALSE
	int		ret_exit_status; // TRUE or FALSE
}				t_commands;

t_commands	*parser(char *buff);
int	get_char_index(char *str, char c);

#endif