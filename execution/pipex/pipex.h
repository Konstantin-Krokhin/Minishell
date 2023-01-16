/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:19:53 by kokrokhi          #+#    #+#             */
/*   Updated: 2023/01/11 16:51:34 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdio.h"
# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include "pipex.c"
# include "pipex_helper.c"
# include "fcntl.h"

char	*find_path(char **envp, int i);
char	*getting_cmd_path(char *argv, char **envp);
void	do_child_work(char *argv, char **envp,
			int pipe_ends[2], int out_fd);
void	open_files(int argc, char **argv, int *in_file, int *out_file);
// int	wait_dup_fd_close(int pid, int pipe_ends[2], int i);
// int	calc_size(char **argv);
// int	pipe_and_fork(int pipe_ends[2], pid_t *pid);
// int	close_and_return(int in_file, int out_file);

#endif