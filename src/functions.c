/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:46:20 by asimon            #+#    #+#             */
/*   Updated: 2022/03/02 16:46:27 by asimon           ###   ########.fr       */
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
	if (bol == 3)
		return (i);
	ft_error("minishell", "syntax error unclosed quotes\n");
	return (-1);
}

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int		ft_cmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		while (*s1 && *s2)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		return (1);
	}
	return (0);
}

void	ft_error(char *prog, char *msg)
{
	t_shell		buff;

	buff = shell;
	write(2, prog, ft_strlen(prog));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	buff.error = 1;
}