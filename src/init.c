/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:16:10 by asimon            #+#    #+#             */
/*   Updated: 2022/03/19 21:16:11 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	init_shell(char **penv)
{
	shell.cmds = NULL;
	shell.error = 0;
}

t_cmd	*init_cmd(t_cmd	*cmd)
{
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	cmd->herdoc_extend = 0;
	cmd->herdoc_file = NULL;
	return (cmd);
}

void	reinit_shell()
{
	t_cmd		*cmd;
	t_cmd		*next;
	int			i;

	i = 0;
	cmd = shell.cmds;
	next = NULL;
	if (cmd != NULL)
		next = cmd->next;
	while (cmd != NULL)
	{
		next = cmd->next;
		if (cmd->args != NULL)
		{
			while (cmd->args[i] != NULL)
				free(cmd->args[i++]);
			free(cmd->args);
			i = 0;
		}
		free(cmd);
		cmd = next;
	}
}
