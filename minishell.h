/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:29:36 by mgranero          #+#    #+#             */
/*   Updated: 2023/01/24 21:18:00 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h> // printf
# include <stdlib.h> // free
# include <readline/readline.h> //readline
# include <readline/history.h> //history
# include <signal.h> //signal handlers


//own libraries
# include "libft/libft.h"
# include "parser/parser.h"


// Colors for the terminal
# define CNRM  "\x1B[0m"
# define CRED  "\x1B[31m"
# define CGRN  "\x1B[32m"
# define CYEL  "\x1B[33m"
# define CBLU  "\x1B[34m"
# define CMAG  "\x1B[35m"
# define CCYN  "\x1B[36m"
# define CWHT  "\x1B[37m"


#endif
