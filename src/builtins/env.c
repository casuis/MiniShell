/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:32:39 by asimon            #+#    #+#             */
/*   Updated: 2022/05/25 21:32:40 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void    built_env(t_cmd *cmds)
{
	t_env *buff;

	buff = shell.env;
	while (buff != NULL)
	{
		if (buff->no_value == 0)
		{
			write(cmds->fd_out, buff->key, ft_strlen(buff->key));
			write(cmds->fd_out, "=", 1);
			write(cmds->fd_out, buff->value, ft_strlen(buff->value));
			write(cmds->fd_out, "\n", 1);
		}
		buff = buff->next;
	}
	if (shell.env != NULL)
		shell.last_return = 0;
}
