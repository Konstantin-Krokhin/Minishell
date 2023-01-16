/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:17:35 by kokrokhi          #+#    #+#             */
/*   Updated: 2023/01/16 20:00:03 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errno.h"
#include "string.h"

void	display_error_msg(char *cmd, char *additional_cmd, void *ptr_to_free)
{
	char	*msg;

	msg = NULL;
	if (ptr_to_free)
		free(ptr_to_free);
	if (ft_strlen(additional_cmd) > 0)
	{
		msg = ft_strjoin(cmd, additional_cmd);
		perror(msg);
		free(msg);
	}
	else
		perror(cmd);
	exit(EXIT_FAILURE);
}

char	*find_path(char **envp, int i)
{
	char	*env_path;

	env_path = NULL;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		{
			env_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			break ;
		}
	}
	return (env_path);
}

char	*getting_cmd_path(char *argv, char **envp)
{
	char	*env_path;
	char	*cmd_path;
	char	**paths;
	char	*tmp;
	int		i;

	env_path = find_path(envp, -1);
	paths = ft_split(env_path, ':');
	i = -1;
	while (paths[++i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
	}
	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], argv);
		if (!(access(cmd_path, F_OK | X_OK)))
			break ;
		free (cmd_path);
	}
	return (cmd_path);
}

void	do_child_work(char *argv, char **envp,
						int pipe_ends[2], int out_fd)
{
	char	*cmd_path;
	char	**cmd;

	printf("-%d-", out_fd);
	//dup2(out_fd, STDOUT_FILENO);
	close(pipe_ends[0]);
	close(pipe_ends[1]);
	cmd = ft_split(argv, ' ');
	cmd_path = getting_cmd_path(cmd[0], envp);
	if (!cmd_path)
		display_error_msg("Path failed", "", cmd);
	if (execve(cmd_path, cmd, envp) == -1)
		display_error_msg("command not found: ", cmd[0], cmd);
}

// void	open_files(int argc, char **argv, int *in_file, int *out_file)
// {
// 	*in_file = open(argv[1], O_RDONLY);
// 	*out_file = open(argv[argc - 1], O_RDWR | O_CREAT \
// 														| O_TRUNC, 0666);
// 	if (*in_file == -1)
// 		display_error_msg("Opening infile failed! ", "", NULL);
// 	if (*out_file == -1)
// 		display_error_msg("Opening outfile failed! ", "", NULL);
// 	dup2(*in_file, STDIN_FILENO);
// }
