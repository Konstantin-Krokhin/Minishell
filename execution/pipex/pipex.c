/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:51:09 by kokrokhi          #+#    #+#             */
/*   Updated: 2023/01/11 16:52:31 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_dup_fd_close(int pid, int pipe_ends[2], int i)
{
	waitpid(pid, NULL, 0);
	dup2(pipe_ends[0], STDIN_FILENO);
	close(pipe_ends[0]);
	close(pipe_ends[1]);
	return (++i);
}

int	calc_size(char **argv)
{
	int	size;

	size = 0;
	while (argv[size] != 0)
		size++;
	return (size);
}

int	pipe_and_fork(int pipe_ends[2], pid_t *pid)
{
	if (pipe(pipe_ends) == -1)
		return (1);
	*pid = fork();
	if (*pid == -1)
		return (1);
	return (0);
}

// int	close_and_return(int in_file, int out_file)
// {
// 	close(in_file);
// 	close(out_file);
// 	return (0);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int		pipe_ends[2];
// 	pid_t	pid;
// 	int		out_file;
// 	int		in_file;
// 	int		i;

// 	if (argc < 5 || envp == 0)
// 		return (printf("Error! Format: in_file cmd1 cmd2 ... cmdn out_file"));
// 	i = 0;
// 	open_files(argc, argv, &in_file, &out_file);
// 	while (i < argc - 3)
// 	{
// 		if (pipe_and_fork(pipe_ends, &pid) == 1)
// 			return (printf("Fork failed!"));
// 		else if (pid == 0)
// 		{
// 			if (i == calc_size(argv) - 4)
// 				do_child_work(argv[i + 2], envp, pipe_ends, out_file);
// 			else
// 				do_child_work(argv[i + 2], envp, pipe_ends, pipe_ends[1]);
// 		}
// 		i = wait_dup_fd_close(pid, pipe_ends, i);
// 	}
// 	return (close_and_return(in_file, out_file));
// }
