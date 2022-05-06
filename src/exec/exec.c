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

// void	ft_pipe_exec(t_cmd *cmd, char **path)
// {
// 	int		pid;
// 	int		pipe_fd[2];

// 	pipe(pipe_fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		execve(cmd->cmd, cmd->args, path);
// 		printf("In child\n");
// 	}
// 	else
// 	{
// 		waitpid(pid, shell.last_return, NULL);
// 		printf("In parent\n");
// 	}
// }

void	ft_execution(t_cmd *cmd,  char **path)
{
	int		pid;
	int		pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		if (cmd->fd_out == 1 && cmd->next != NULL)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], 1);
		}
		execve(cmd->cmd, cmd->args, path);
	}
	else
	{
		waitpid(pid, &shell.last_return, 0);
		if (cmd->next != NULL)
			cmd = cmd->next;
		else
			return ;
		pid = fork();
		if (pid == 0)
		{
			if (cmd->fd_in == 0)
			{
				close(pipe_fd[1]);
				dup2(pipe_fd[0], 0);
			}
			dup2(cmd->fd_out, 1);
			cmd->cmd = set_cmd_path(cmd, path);
			execve(cmd->cmd, cmd->args, NULL);
		}
		else
		{
			printf("valeur de ret: |%d|\n", shell.last_return);
			waitpid(pid, &shell.last_return, 0);
		}
	}
}

void	ft_exec()
{
	char	**path;
	char	**env;
	t_cmd	*cmd;

	cmd = shell.cmds;
	path = ft_split(get_va_env_value("PATH"), ':');
	env = get_env_tab(); // GOOD
	if (cmd == NULL)
	{
		printf("sori pour NULL\n");
		return ;
	}
	if (is_builtin(cmd->cmd))
		printf("yes\n");
	// lancement de exec_builtin
	else
	{	
		cmd->cmd = set_cmd_path(cmd, path);
		// printf("valeur de cmd: |%s|\n", cmd->cmd);
		// Creation du path complet en cmd
		// // FORK de l'environement pour execution
		// if (cmd->next != NULL && cmd->fd_out == 1)
		// 	ft_pipe_exec(cmd);
		// else
		 	ft_execution(cmd, path);
	}
}