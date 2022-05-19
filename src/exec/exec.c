/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:02:58 by asimon            #+#    #+#             */
/*   Updated: 2022/05/19 22:45:05 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_exec.h"

void	ft_child(int fd_in, int pipe_fd[], t_cmd *cmd)
{
	if (cmd->fd_in == 0)
	{
		dup2(fd_in, 0);
		if (fd_in != 0)
			close(fd_in);
	}
	else
		dup2(cmd->fd_in, 0);
	if (cmd->next != NULL && cmd->fd_out == 1)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
	}
	else
	{
		dup2(cmd->fd_out, 1);
		close(pipe_fd[1]);
	}
	close(pipe_fd[0]);
	execve(cmd->cmd, cmd->args, env);
	exit(EXIT_FAILURE);
}

void	ft_exec_cmd(t_cmd *cmd, char **env)
{
	int		pid;
	int		pipe_fd[2];
	int		fd_in;
	int		wait_ret;

	wait_ret = 0;
	fd_in = 0;
	while (cmd != NULL)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
			ft_child(fd_in, pipe_fd, cmd);
		close(pipe_fd[1]);
		if (fd_in != 0)
			close(fd_in);
		fd_in = pipe_fd[0];
		cmd = cmd->next;
	}
	if (fd_in != 0)
		close(fd_in);
	while (wait_ret != -1)
		wait_ret = wait(&shell.last_return);
}

void	set_all_cmd(char **path)
{
	t_cmd	*cmd;

	cmd = shell.cmds;
	while (cmd != NULL)
	{
		cmd->cmd = set_cmd_path(cmd, path);
		cmd = cmd->next;
	}
}

void	ft_exec(void)
{
	char	**path;
	char	**env;
	t_cmd	*cmd;

	cmd = shell.cmds;
	path = ft_split(get_va_env_value("PATH"), ':');
	env = get_env_tab();
	set_all_cmd(path);
	if (cmd == NULL || cmd->cmd == NULL)
		return ;
	if (is_builtin(cmd->cmd))
		printf("yes\n");
	else
		ft_exec_cmd(cmd, env);
}
