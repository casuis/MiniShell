/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:53:04 by asimon            #+#    #+#             */
/*   Updated: 2022/02/27 14:53:06 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	deffine_cmd_sep(char *str, int pos, t_cmd *cmd)
{
	int		i;
	int		bol;

	i = 0;
	bol = 3;
	if (str == NULL)
		return ;
	while (str[i] && i < pos && shell.error == 0)
	{
		while (str[i] && str[i] == ' ' && i < pos)
			i++;
		if (str[i] == '<' && bol == 3)
			i = parse_in_file(&str[i], (pos - i), cmd);
		else if (str[i] == '>' && bol == 3)
			i = parse_out_file(&str[i], (pos - i), cmd);
		else if (str[i] == '\'' || str[i] == '"')
			i += quote_closed(str[i], &bol);
		if (str[i] != '\0')
			i++;
	}
}

void	parsing(char *str)
{
	int		y;
	int		balise[2];
	char	*work_str;
	char	*buff;
	t_cmd	*cmd;

	y = 0;
	balise[0] = 0;
	balise[1] = 0;
	cmd = get_last_elem();
	work_str = NULL;
	while (str[balise[0]] && shell.error == 0)
	{
		balise[1] += get_next_pipe(&str[balise[1]]);
		if (shell.error == 1)
			break ;

		// creer une nouvelle cmd - DONE
		cmd = ft_add_list(cmd);
		
		// defini les fds - MISSING DEF
		deffine_cmd_sep(str, balise, cmd);

		// set la work str - DONE
		work_str = set_work_str(str, balise[0], balise[1]);
		buff = work_str;
		
		// set les cmd & args - DONE
		set_cmd_arg(&work_str, cmd);

		free(buff);
		// avance i jusqu'au prochain tour
		if (str[balise[1]] != '\0')
			balise[1]++;
		balise[0] = balise[1];
	}

}
