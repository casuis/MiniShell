/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:10:26 by asimon            #+#    #+#             */
/*   Updated: 2022/04/05 15:10:27 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/minishell_exec.h"

char	*set_cmd_path(t_cmd *cmd, char **path)
{
	char	*buff;
	char	*cmd_path;
	int		i;

	i = 0;
	if (path == NULL || cmd == NULL)
		return (NULL);
	if (access(cmd->cmd, F_OK) != -1)
		return (cmd->cmd);
	buff = ft_strjoin(cmd, path[i]);
	cmd_path = ft_strjoin(buff, "/");
	free(buff);
	while (acces(cmd_path, F_OK) == -1 && path[i] != NULL)
	{
		i++;
		buff = ft_strjoin(cmd, path[i]);
		cmd_path = ft_strjoin(buff, "/");
		free(buff);
	}
	if (path[i] == NULL)
		shell.last_return = 127;
	free(cmd);
	return (cmd_path);
}
