/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:32:56 by asimon            #+#    #+#             */
/*   Updated: 2022/05/25 21:32:57 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void    built_unset(t_cmd *cmds)
{
	t_env	*buff;
	t_env	*tmp;
	int		i;

	i = 0;
	if (cmds == NULL || cmds->args[1] == NULL || shell.env == NULL)
		return ;
	buff = shell.env;
	tmp = buff;
	while (buff != NULL)
	{
		if (ft_strcmp(buff->key, cmds->args[1]))
		{
			if (i != 0)
				tmp->next = buff->next;
			else
				shell.env = buff->next;
			free(buff);
			break ;
		}
		tmp = buff;
		buff = buff->next;
		i++;
	}
}
