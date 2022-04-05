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

void	set_pipe_fd(t_cmd *cmd, int pipe_fd)
{
}

void	ft_pipe_exec(t_cmd *cmd)
{
	int		pid;
	int		pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid)
	{
	}
	else
	{

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
		return ;
	if (is_builtin(cmd->cmd))
		printf("yes\n");
	// lancement de exec_builtin
	else
	{	
		cmd->cmd = set_cmd_path(cmd, path);
		// Creation du path complet en cmd
		// FORK de l'environement pour execution
		if (cmd->next != NULL && cmd->fd_out == 1)
			ft_pipe_exec(cmd);
		else
			ft_exec(cmd);
	}
}