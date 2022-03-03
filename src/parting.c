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

int	get_next_pipe(char *str)
{
	int		i;
	int		bol;

	i = 0;
	bol = 3;
	while (str[i])
	{
		if (str[i] == '"' && bol > 2)
			bol = 1;
		else if (str[i] == '\'' && bol > 2)
			bol = 2;
		else if (str[i] == '"' && bol == 1)
			bol = 3;
		else if (str[i] == '\'' && bol == 2)
			bol = 3;
		else if (bol > 2 && str[i] == '|')
			return (i);
		i++;
	}
	if (bol != 3)
		return (-1);
	return (i);
}


int	deffine_cmd_sep(char *str, int pos)
{
	int		i;
	int		y;
	t_shell	buff;

	i = 0;
	y = 0;
	buff = shell;
	while (i < pos)
	{
		while (str[y] != ' ')
			y++;
		if (buff.cmds.cmd == NULL)
			buff.cmds.cmd = ft_strncpy(&str[i], y);
		else
		// gestion des arguments avec "" && '' aussi 
			// buff.cmds.arg
		i += y;
	}
}

t_cmd	*parting(char *str)
{
	int		i;
	int		balise;

	i = 0;
	balise = 1;
	while (balise > 0)
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

int main(int argc, char const *argv[])
{
	char	*test;

	test = "Salut ceci est un test | apres pipe | apres 2 pipe |\n";
	parting(test);
	return 0;
}

