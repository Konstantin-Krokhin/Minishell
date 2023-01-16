/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:21:04 by mgranero          #+#    #+#             */
/*   Updated: 2023/01/16 19:36:00 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution/pipex/pipex.h"

void orLogic()
{

}

int	pipe_and_fork(int pipe_ends[2], pid_t *pid)
{
	if (pipe(pipe_ends) == -1)
		return (1);
	printf("\n!!pid = %d\n", *pid);
	*pid = fork();
	printf("\n!!pid = %d\n", *pid);
	if (*pid == -1)
		return (1);
	return (0);
}

void pipex(char	**argv, char **envp, int num_of_pipes)
{
	int		pipe_ends[2];
	pid_t	pid;
	// int		out_file;
	// int		in_file;
	int		i;

	i = 0;
	// open_files(argc, argv, &in_file, &out_file);
	while (i < num_of_pipes + 2)
	{
		printf("IN PIPEX WHILE !");
		if (pipe_and_fork(pipe_ends, &pid) == 1)
			printf("Fork failed!");
		else if (pid == 0)
		{
			printf("pid = 0!");
			if (i == calc_size(argv) - 4)
				do_child_work(argv[i + 2], envp, pipe_ends, STDOUT_FILENO);
			else
				do_child_work(argv[i + 2], envp, pipe_ends, pipe_ends[1]);
		}
		printf("ibefore = %d", i);
		i = wait_dup_fd_close(pid, pipe_ends, i);
		printf("iafter = %d!", i);
	}
	// return (close_and_return(in_file, out_file));
}

int	main(int argc, char **argv, char **envp)
{
	char	*buff;
	int		num_of_pipes = 0;
	// char	**argv_splitted;
	argv = 0;
	argc = 0;
	int i = 0;

	printf("----- Welcome to Minishell -----\n");
	while (1)
	{
		buff = readline(">>");
		if (ft_strlen(buff) > 0)
			 add_history(buff);
		
		// PARSE INPUT
		// CALL COMMANDS
		
		// PIPES
		while (buff[i] != '\0')
		{
			if (buff[i] == '|' && buff[i + 1] != '|')
				num_of_pipes++;
			else if (buff[i] == '|' && buff[i + 1] == '|')
				orLogic();
			i++;
		}
		//argv_splitted = ft_split(buff, '|');
		if (ft_memcmp(buff, "exit", ft_strlen(buff)) == 0)
		{
			free(buff);
			return(0);
		}
		if (num_of_pipes > 0)
			pipex(argv, envp, num_of_pipes);
			
		// REDIRECT
		printf("%s\n",buff);
		free(buff);
	}
	return (0);
}
