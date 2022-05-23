/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:54:06 by asimon            #+#    #+#             */
/*   Updated: 2022/05/23 05:55:22 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"

void	parse_in_file(char **str, t_cmd *cmd)
{
	*str += 1;
	if (**str == '>')
		ft_error("minishell", "operator '<>' does not have to be recreated\n", 1);
	else if (**str == '<')
		cmd->fd_in = parse_herdoc(str, cmd);
	else
	{
		while (**str && **str == ' ')
			*str += 1;
		if (**str == '\0')
			ft_error("minishell",
				"syntax error near unexpected token 'newline'\n", 1);
		else if (**str == '|' || **str == '<' || **str == '>')
			ft_error("minishell", "syntax error near unexpected token\n", 1);
		cmd->fd_in = set_fd_in(str);
	}
}

void	parse_out_file(char **str, t_cmd *cmd)
{
	int		mod;

	mod = 0;
	*str += 1;
	if (**str == '<')
		ft_error("minishell", "syntax error\n", 1);
	else if (**str == '>')
	{
		mod = 1;
		*str += 1;
	}
	while (**str && **str == ' ' && shell.error == 0)
		*str += 1;
	if (**str == '<' || **str == '>' || **str == '\0')
		ft_error("minishell", "syntax syntax error near unexpected token\n", 1);
	if (shell.error == 0)
		cmd->fd_out = set_fd_out(str, mod);
}

static char	*ft_quote_undle(char **str, char *ret)
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
	return (ret);
}

char	*get_cmd_fd(char **str)
{
	char	*ret;
	char	**buff;

	ret = NULL;
	buff = malloc(sizeof (char *) * 2);
	if (buff == NULL)
		return (NULL);
	gb_col_add_list((void *)buff);
	while (**str && **str != ' ')
	{
		if (**str == '"' || **str == '\'')
			ret = ft_quote_undle(str, ret);
		else if (**str == '$')
		{
			*str += 1;
			buff[0] = get_va_env(*str);
			buff[1] = ret;
			ret = ft_strjoin(ret, buff[0]);
		}
		else
			ret = ft_add_char(ret, str);
	}
	return (ret);
}
