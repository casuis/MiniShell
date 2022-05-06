/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:14:46 by asimon            #+#    #+#             */
/*   Updated: 2022/03/16 22:14:51 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"


int	pass_file(char *str, int i, int balise, int bol)
{
	if (str[i + 1] == '<' || str[i + 1] == '>')
		i++;
	i++;
	while (str[i] == ' ' && i < balise)
		i++;
	while (str[i] != ' ' && i < balise)
		i++;
	return (i);
}

static int	get_work_str_size(char *str, int i, int balise)
{
	int		size;
	int		bol;

	size = 0;
	bol = 3;
	while (i < balise)
	{
		if ((str[i] == '<' || str[i] == '>') && bol == 3)
			i = pass_file(str, i, balise, bol);
		else
		{
			if (str[i] == '\'' || str[i] == '"')
				quote_closed(str[i], &bol);
			size++;
			i++;
		}
	}
	return (size);
}

char	*set_work_str(char *str, int i, int balise)
{
	int		bol;
	int		size;
	char	*ret;
	int		ret_i;

	bol = 3;
	ret_i = 0;
	size = get_work_str_size(str, i, balise);
	ret = malloc(sizeof(char) * (size + 1));
	gb_col_add_list((void *)ret);
	while (i  < balise)
	{
		if ((str[i] == '<' || str[i] == '>') && bol == 3)
			i = pass_file(str, i, balise, bol);
		else
		{
			if (str[i] == '\'' || str[i] == '"')  
				quote_closed(str[i], &bol);
			ret[ret_i] = str[i];
			ret_i++;
			i++;
		}
	} 
	ret[ret_i] = '\0';
	return (ret);
}
