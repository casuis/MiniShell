/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:53:04 by asimon            #+#    #+#             */
/*   Updated: 2022/05/25 21:51:12 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"

void	deffine_cmd_sep(char *str, int i, int pos, t_cmd *cmd)
{
	int		bol;
	char	*work_str;

	bol = 3;
	work_str = set_in_out_work_str(str, i, pos);
	if (str == NULL || work_str == NULL)
		return ;
	while (*work_str && shell.error == 0)
	{
		while (*work_str && *work_str == ' ')
			work_str++;
		if (*work_str == '<' && bol == 3)
			parse_in_file(&work_str, cmd);
		else if (*work_str == '>' && bol == 3)
			parse_out_file(&work_str, cmd);
		else if (*work_str == '\'' || *work_str == '"')
			work_str += quote_closed(*work_str, &bol);
		if (*work_str != '\0')
			work_str++;
	}
}

static int	check_null(char *str)
{
	int		i;
	int		bol;
	int		pipe;

	i = 0;
	bol = 0;
	pipe = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '|')
			bol = 1;
		if (str[i] == '|')
		{
			bol = 0;
			while (str[++i] && str[i] != '|')		
				if (str[i] != ' ')
					bol = 1;
			if (bol == 0)
				ft_error("minishell", "syntax error\n", 1);
		}
		if (str[i] != '\0')
			i++;
	}
	return (bol);
}

void	parsing(char *str)
{
	int		balise[2];
	char	*work_str;
	t_cmd	*cmd;

	balise[0] = 0;
	balise[1] = 0;
	cmd = get_last_elem();
	work_str = NULL;
	if (check_null(str) == 0)
		return ;
	while (str[balise[0]] && shell.error == 0)
	{
		balise[1] += get_next_pipe(&str[balise[1]]);
		if (shell.error == 1)
			break ;
		cmd = ft_add_list(cmd);
		deffine_cmd_sep(str, balise[0], balise[1], cmd);
		work_str = set_work_str(str, balise[0], balise[1]);
		set_cmd_arg(&work_str, cmd);
		if (str[balise[1]] != '\0')
			balise[1]++;
		balise[0] = balise[1];
	}
}
