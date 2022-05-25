/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:32:26 by asimon            #+#    #+#             */
/*   Updated: 2022/05/25 21:59:27 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_str_duplicate(char *str)
{
	char	*ret;
	int	i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_update_pwd()
{
	t_env	*old;
	t_env	*new;

	old = shell.env;
	new = shell.env;
	while (old != NULL && ft_strcmp(old->key, "OLDPWD") == 0)
		old = old->next;
	while (new != NULL && ft_strcmp(new->key, "PWD") == 0)
		new = new->next;
	free(old->value);
	old->value = ft_str_duplicate(new->value);
	free(new->value);
	new->value = getcwd(NULL, 0);
}

void	built_cd(t_cmd *cmds)
{
	if (cmds->args[1] == NULL || cmds->args[2] != NULL)
	{
		ft_error("minishell", " cd: Wrong number of argument\n", 1);
		return ;
	}
	if (chdir(cmds->args[1]) != -1)
	{
		if (shell.pid != 0)
			ft_update_pwd();
		shell.last_return = 0;
	}
	else
		shell.last_return = 1;
}
