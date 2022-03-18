/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:00:39 by asimon            #+#    #+#             */
/*   Updated: 2022/03/16 21:00:40 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// attention au quotes pour les va_ar
// D'abbord verifier si on est entre quote

char	*get_cmd(char **str, t_cmd *cmds)
{
	int		bol;
	char	*ret;
	

	bol = 3;
	while (**str && (**str != ' ' && bol == 3))
	{
		if (**str == '\'' && bol == 3)
			ret = ft_add_single_quote(ret, str);
		else if (**str == '"' && bol == 3)
			ret = ft_add_double_quote(ret, str);
		else if (**str == '$' && bol == 3)
			ret = ft_add_var_env(ret, str, cmds);
		else
			ret = ft_add(ret, str);
	}
}

void	set_cmd_arg(char *work_str, t_cmd *cmds)
{
	int		i;
	char	*buff;

	i = 0;
	buff = work_str;
	while (work_str && shell.error == 0)
	{
		if (i == 0)
			cmds->cmd = get_cmd(&work_str, cmds); 
		else
			cmds->args = ft_add_intable(cmds->args, get_cmd(&work_str, cmds));
		i++;
	}
}

