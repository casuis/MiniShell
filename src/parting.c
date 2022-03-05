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

int	parse_in_file(char *str, int pos)
{
	int			i;
	t_shell		buff;
	char		*cmd_buff;
	int			y;

	i = 0;
	y = 0;
	buff = shell;
	if (str[i + 1] == '>')
		ft_error("Error: this operator does not have to be recreated\n");
	if (str[i + 1] == '<')
		parse_herdoc();
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i + y] && ((i + y) < pos && str[i + y] != ' '))
		y++;
	if (buff.cmds.cmd == NULL)
		buff.cmds.cmd = ft_add_list(NULL);
	else if (buff.cmds.cmd && buff.cmds.args == NULL)
		buff.cmds.args = ft_add_arg(str);

}

void	deffine_cmd_sep(char *str, int pos)
{
	int		i;
	t_shell	buff;

	i = 0;
	buff = shell;
	if (str == NULL)
		return ;
	while (str[i] && i < pos)
	{
		while (str[i] && str[i] == ' ' && i < pos)
			i++;
		if (str[i] == '<')
			i = parse_in_file(&str[i], (pos - i));
		else if (str[i] == '>')
			i = parse_out_file(&str[i], (pos - i));
		else if (str[i] == '$')
			i = parse_var_env(&str[i], (pos - i));
		else if (str[i] == '\'' || str[i] == '"')
			i = parse_quotes(&str[i], (pos - i));
		else if (str[i] != ' ' && str[i] != '\0')
			i = create_cmd_arg(&str[i],(pos - i));
		if (str[i] != '\0')
			i++;
	}
}

t_cmd	*parting(char *str)
{
	int		i;
	int		balise;

	i = 0;
	balise = 1;
	while (balise > 0 && str[i])
	{
		balise = get_next_pipe(&str[i]);
		write(1, &str[i], balise) ;
		i += balise;
		if (str[i] != '\0')
			i++;
		//printf("%s", &str[i]);
		// if (balise != -1)
		// 	deffine_cmd_sep(&str[i], balise);
		// else
		// 	ft_error("Error: unclosed quote\n");
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	char *str;

	// str = "salut < ";
	deffine_cmd_sep(argv[1], 100);
	return (0);
}
