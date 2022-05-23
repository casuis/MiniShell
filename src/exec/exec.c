/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:02:58 by asimon            #+#    #+#             */
/*   Updated: 2022/05/23 05:48:28 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_exec.h"

void	monitoring_builtin(t_cmd *cmds, int mod)
{
	if (mod == 1)
		built_cd(cmds);
	else if (mod == 2)
		built_echo(cmds);
	else if(mod == 3)
		built_pwd(cmds);
	else if (mod == 4)
		built_export(cmds);
	else if (mod == 5)
		built_unset(cmds);
	else if (mod == 6)
		built_env(cmds);
	else if (mod == 7)
		built_exit(cmds);
}

static void	ft_exec(t_cmd *cmd, char **env)
{
	int		mod;

	mod = 0;
	mod = is_builtin(cmd->cmd);
	if (mod > 0)
	{
		monitoring_builtin(cmd, mod);
		if (mod != 7)
			exit(EXIT_FAILURE);
	}
	else
		execve(cmd->cmd, cmd->args, env);
	perror((const char *)cmd->cmd);
	exit(EXIT_FAILURE);

}

void	ft_child(int fd_in, int pipe_fd[], t_cmd *cmd, char **env)
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
	ft_exec(cmd, env);
}

void	ft_exec_cmd(t_cmd *cmd, char **env)
{
	int		pipe_fd[2];
	int		fd_in;
	int		wait_ret;

	wait_ret = 0;
	fd_in = 0;
	while (cmd != NULL)
	{
		pipe(pipe_fd);
		shell.pid = fork();
		if (shell.pid == -1)
			exit(EXIT_FAILURE);
		else if (shell.pid == 0)
			ft_child(fd_in, pipe_fd, cmd, env);
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

void	ft_core_exec(void)
{
	char	**path;
	char	**env;
	t_cmd	*cmd;
	int		mod;

	mod = 0;
	cmd = shell.cmds;
	path = ft_split(get_va_env_value("PATH"), ':');
	env = get_env_tab();
	while (cmd != NULL)
	{
		if (is_builtin(cmd->cmd) == 0)
			cmd->cmd = set_cmd_path(cmd, path);
		cmd = cmd->next;
	}
	cmd = shell.cmds;
	if (shell.error != 0)
		return ;
	if (cmd == NULL || cmd->cmd == NULL)
		return ;
	mod = is_builtin(cmd->cmd);
	if (cmd->next == NULL && mod > 0)
		monitoring_builtin(cmd, mod);
	else
		ft_exec_cmd(cmd, env);
}
