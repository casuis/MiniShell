/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:10:26 by asimon            #+#    #+#             */
/*   Updated: 2022/05/19 21:10:20 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/minishell_exec.h"

char	*set_str_path(char *path, t_cmd *cmd)
{
	char	*ret;
	char	*buff;
	char	*tmp;

	buff = ft_strjoin(path, "/");
	tmp = buff;
	ret = ft_strjoin(buff, cmd->cmd);
	free(tmp);
	return (ret);
}

char	*set_cmd_path(t_cmd *cmd, char **path)
{
	char	*cmd_path;
	int		i;

	i = 0;
	if (path == NULL || cmd == NULL)
		return (NULL);
	if (access(cmd->cmd, F_OK) != -1)
		return (cmd->cmd);
	cmd_path = set_str_path(path[i], cmd);
	while (access(cmd_path, F_OK) == -1 && path[++i] != NULL)
		cmd_path = set_str_path(path[i], cmd);
	if (path[i] == NULL)
	{
		free(cmd_path);
		shell.last_return = 127;
		return (NULL);
	}
	return (cmd_path);
}
