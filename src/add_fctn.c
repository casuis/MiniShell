/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fctn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:38:14 by asimon            #+#    #+#             */
/*   Updated: 2022/03/18 00:38:15 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_size(char *str, char del)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != del && str[i])
		i++;
	return (i);
}

char	*set_new_ret(char *old, int size, int *i)
{
	char		*ret;
	char		*buff;

	buff = old;
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)	
		return (NULL);
	if (old != NULL)
		while (old[++*i])
			ret[*i] = old[*i];
	if (buff != NULL)
		free(buff);
	return (ret);
}

void	*send_new_arg(char *str, t_cmd *cmd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			add_arg(&str[i], cmd);
			break ;
		}
	}
}

void	add_arg(char *str, t_cmd *cmd)
{
	int		i;
	int		y;
	int		size;
	char	**ret;

	while (cmd->args[size] != NULL)
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (cmd->args[y] != NULL)
	{
		ret[y] = cmd->args[y];
		y++;
	}
	size = 0;
	while (str[size] && str[size] != ' ')
		size++;
	ret[y] = ft_strncpy(str, size);
	ret[++y] = NULL;
	free(cmd->args);
	cmd->args = ret;
}

int		main(int argc, char **argv, char *envp)
{
	
}