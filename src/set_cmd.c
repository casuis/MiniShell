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


char	*ft_set_taken(char *str, int *i)
{
	char	*ret;
	int		bol;

	// Creation d'une str pour cmd ou j'add au fur et mesure
	// Meme procede pour argument
	// Permet de faire une routine?
	// Creation d'une liste chaine pour str?
	// Bonne nuit arthur
	bol = 3;
	while (str[*i] && str[*i] != ' ' && shell.error == 0)
	{
		if (str[*i] == '&' && bol == 3)
			ret = cmd_find_va_env(str, i);
		else if (str[*i] == '\'') 

	}
}

void	set_cmd_arg(char *work_str, t_cmd *cmd)
{
	int		i;
	char	*rest;

	i = 0;
	while (work_str[i] && shell.error == 0)
	{
		// Set cmd  
		rest = ft_set_taken(work_str, &i);
		create_args(work_str, &i);
	}
}

