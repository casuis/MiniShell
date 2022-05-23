/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_herdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:20:54 by asimon            #+#    #+#             */
/*   Updated: 2022/05/23 05:50:20 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"

char	*ft_add_single_quote_herdoc(char *old, char **str, char del)
{
	int			i;
	char		*ret;
	int			size;

	i = 0;
	size = ft_strlen(old) + get_size(*str, del);
	ret = set_new_ret(old, size, &i);
	while (**str && **str != del)
	{
		ret[i++] = **str;
		*str += 1;
	}
	if (**str == '\'')
		*str += 1;
	ret[i] = '\0';
	return (ret);
}

char	*get_cmd_quote_herdoc(char *ret, char **str, t_cmd *cmd)
{
	cmd->herdoc_extend = 1;
	if (**str == '\'')
	{
		*str += 1;
		ret = ft_add_single_quote_herdoc(ret, str, '\'');
	}
	else if (**str == '"')
	{
		*str += 1;
		ret = ft_add_single_quote_herdoc(ret, str, '"');
	}
	return (ret);
}

char	*get_herdoc_cmd(char **str, t_cmd *cmd)
{
	char	*ret;

	ret = NULL;
	while (**str && **str != ' ')
	{
		if (**str == '\'' || **str == '"')
			ret = get_cmd_quote_herdoc(ret, str, cmd);
		else
			ret = ft_add_char(ret, str);
	}
	return (ret);
}

char	*set_herdoc_del(t_cmd *cmd, char **work_str)
{
	char	*cmd_buff;

	while (**work_str == ' ')
		*work_str += 1;
	cmd_buff = get_herdoc_cmd(work_str, cmd);
	return (cmd_buff);
}
