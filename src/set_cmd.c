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

// 1 ligne en trop
char	*get_cmd(char **str, t_cmd *cmds)
{
	char	*ret;

	ret = NULL;
	
	while (**str && **str != ' ')
	{
		if (**str == '\'')
		{
			*str += 1;
			ret = ft_add_single_quote(ret, str);
		}
		else if (**str == '"')
		{
			*str += 1;
			ret = ft_add_double_quote(ret, str);
			*str += 1;
		}
		else if (**str == '$')
		{
			*str +=1;
			ret = ft_add_var_env(ret, str, cmds); 
		}
		else
			ret = ft_add_char(ret, str);
	}
	return (ret);
}

char	**add_intable(char **args, char *str)
{
	int		i;
	int		size;
	char	**ret;

	i = 0;
	size = 0;
	if (args != NULL)
		while (args[size] != NULL)
			size++;
	ret = malloc(sizeof(char *) * (size + 2));
	while (i < size)
	{
		ret[i] = args[i];
		i++;
	}
	ret[i] = str;
	ret[++i] = NULL;
	free(args);
	return (ret);
}

void	set_cmd_arg(char **work_str, t_cmd *cmds)
{
	int		i;
	int		y;
	char	**buff;

	i = 0;
	y = 0;
	buff = work_str;
	while (**work_str && shell.error == 0)
	{
		while (**work_str == ' ')
			*work_str += 1;
		if (i == 0)
			cmds->cmd = get_cmd(work_str, cmds); 
		else
			cmds->args = add_intable(cmds->args, get_cmd(work_str, cmds));
		// ft_test();
		while (**work_str == ' ')
			*work_str += 1;
		i++;
	}
}

