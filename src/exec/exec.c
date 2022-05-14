/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:02:58 by asimon            #+#    #+#             */
/*   Updated: 2022/03/26 18:03:01 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_exec.h"

// void	set_pipe_fd(t_cmd *cmd, int pipe_fd)
// {
// }

void	ft_execution(t_cmd *cmd,  char **path, char **env)
{
	int		pid;
	int		pid2;
	int		wa_pid;
	int		pipe_fd[2];

	pipe(pipe_fd);
	wa_pid = 0;
	pid = fork();
	if (pid == 0)
	{
		if (cmd->fd_out == 1 && cmd->next != NULL)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], 1);
			close(pipe_fd[1]);
		}
		execve(cmd->cmd, cmd->args, env);
	}
	else
	{
		waitpid(-1, &shell.last_return, 0);
		if (cmd->next != NULL)
			cmd = cmd->next;
		else
		{
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			wait(&shell.last_return);
			return ;
		}
		pid2 = fork();
		if (pid2 == 0)
		{
			if (cmd->fd_in == 0)
			{
				close(pipe_fd[1]);
				dup2(pipe_fd[0], 0);
				close (pipe_fd[0]);
			}
			dup2(cmd->fd_out, 1);
			cmd->cmd = set_cmd_path(cmd, path);
			execve(cmd->cmd, cmd->args, env);
		}
		else
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			wa_pid = waitpid(-1, &shell.last_return, 0);
		}
	}
}

void	ft_exec_cmd(t_cmd *cmd, char **path, char **env, int pipe_fd[])
{
	if (cmd->next != NULL)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
	}
	else
		close(pipe_fd[1]);
	close(pipe_fd[0]);
	execve(cmd->cmd, cmd->args, env);
}

void	ft_exec()
{
	char	**path;
	char	**env;
	int		pid;
	int		pipe_fd[2];
	t_cmd	*cmd;
	int   fd_in;

	cmd = shell.cmds;
	path = ft_split(get_va_env_value("PATH"), ':');
	env = get_env_tab(); // GOOD
	if (cmd == NULL)
	{
		printf("sorti pour NULL\n");
		return ;
	}
	if (is_builtin(cmd->cmd))
		printf("yes\n");
	else
	{	
		while (cmd != NULL)
		{
			cmd->cmd = set_cmd_path(cmd, path);
			pipe(pipe_fd);
			if ((pid = fork()) == -1)
				exit(EXIT_FAILURE);
			else if (pid == 0)
			{
				dup2(fd_in, 0); //change the input according to the old one 
				if (cmd->next != NULL)
					dup2(pipe_fd[1], 1);
				close(pipe_fd[0]);
				execve(cmd->cmd, cmd->args, env);
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(&shell.last_return);
				close(pipe_fd[1]);
				fd_in = pipe_fd[0]; //save the input for the next command
				cmd = cmd->next;
			}
		}
	}
}