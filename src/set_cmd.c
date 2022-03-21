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
			printf("valeur de *str entre: |%s|\n", *str);
			ret = ft_add_double_quote(ret, str);
			printf("valeur de *str sorie: |%s|\n", *str);
			printf("valeur de ret: |%s|\n", ret);
		}
		else if (**str == '$')
		{
			*str +=1;
			ret = ft_add_var_env(ret, str, cmds);
		}
		// else
		// {
		// 	ret = 

	}
	return (ret);
}

void	set_cmd_arg(char **work_str, t_cmd *cmds)
{
	int		i;
	char	**buff;

	i = 0;
	buff = work_str;
	while (**work_str && shell.error == 0)
	{
		while (**work_str == ' ')
			*work_str += 1;
		if (i == 0)
			cmds->cmd = get_cmd(work_str, cmds); 
		// else
			// cmds->args = ft_add_intable(cmds->args, get_cmd(&work_str, cmds));
		// printf("valeur de work_str: |%s|\n", *work_str);
		while (**work_str == ' ')
			*work_str += 1;
		i++;
	}
	printf("sorti\n");
}

