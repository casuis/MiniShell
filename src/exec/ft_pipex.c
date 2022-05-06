/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:15:32 by arthur            #+#    #+#             */
/*   Updated: 2021/12/18 10:39:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char **env, char *cmd)
{
	char	*buff;
	char	**tab;
	char	**arg;
	char	*path;

	buff = ft_set_path(env);
	tab = ft_split2(buff);
	free(buff);
	arg = ft_split(cmd);
	path = ft_check_path(tab, arg[0]);
	execve(path, arg, env);
	perror("pipex: ");
}

void	ft_pipe(int fd, char **env, char *cmd)
{
	int	pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		if (fd == 0)
			exit (0);
		else
			ft_exec(env, cmd);
	}
}

void	ft_pipex(t_cmd *cmd, char **str)
{
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	ft_pipe(fd_in, penv, str[2]);
	ft_exec(penv, str[3]);
}
