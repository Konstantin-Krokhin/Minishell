/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:28:23 by mgranero          #+#    #+#             */
/*   Updated: 2023/01/24 21:13:21 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "stdio.h" // also present in main
#include "../libft/libft.h" // also present in main
# include <stdlib.h> // // also present in main

int	parser(char *buff, char *cmd, char **args);

#endif