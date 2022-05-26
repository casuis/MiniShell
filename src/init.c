/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:16:10 by asimon            #+#    #+#             */
/*   Updated: 2022/05/26 19:32:21 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	init_shell(void)
{
	shell.cmds = NULL;
	shell.pid = 1;
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

void	init_gb_col(void)
{
	shell.list = malloc(sizeof(t_gb_col));
	shell.list->ptr = NULL;
	shell.list->next = NULL;
}
